
/*
 * hongzhidao <hongzhidao@gmail.com>
 */

#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>


static char *ngx_http_hello(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
static ngx_int_t ngx_http_hello_handler(ngx_http_request_t *r, int error);


static ngx_command_t ngx_http_hello_commands[] = {

    { ngx_string("hello"),
      NGX_HTTP_LOC_CONF|NGX_CONF_NOARGS,
      ngx_http_hello,
      0,
      0,
      NULL},

    ngx_null_command
};


static ngx_http_module_t ngx_http_hello_module_ctx = {
    NULL,

    NULL,
    NULL,

    NULL,
    NULL,

    NULL,
    NULL
};


ngx_module_t ngx_http_hello_module = {
    NGX_MODULE,
    &ngx_http_hello_module_ctx,
    ngx_http_hello_commands,
    NGX_HTTP_MODULE,
    NULL,
    NULL
};


static u_char ngx_hello_string[] = "hello world";


static ngx_int_t
ngx_http_hello_handler(ngx_http_request_t *r, int error)
{
    ngx_int_t       rc;
    ngx_buf_t       *b;
    ngx_chain_t     *out;

    ngx_chain_t      **ll, *cl;

    r->headers_out.content_type = ngx_list_push(&r->headers_out.headers);
    if (r->headers_out.content_type == NULL) {
        return NGX_ERROR;
    }

    r->headers_out.content_type->key.len = sizeof("Content-Type") - 1;
    r->headers_out.content_type->key.data = (u_char *) "Content-Type";
    r->headers_out.content_type->value.len = sizeof("text/html") - 1;
    r->headers_out.content_type->value.data = (u_char *) "text/html";

    b = ngx_pcalloc(r->pool, sizeof(ngx_buf_t));
    if (b == NULL) {
        return NGX_HTTP_INTERNAL_SERVER_ERROR; 
    }

    out = NULL;
    ll = NULL;

    ngx_alloc_link_and_set_buf(cl, b, r->pool, NGX_ERROR);
    ngx_chain_add_link(out, ll, cl);

    out->buf = b;
    out->next = NULL;

    b->pos = ngx_hello_string;
    b->last = ngx_hello_string + ngx_strlen(ngx_hello_string);
    b->memory = 1;
    b->last_buf = 1;

    r->headers_out.status = NGX_HTTP_OK;
    r->headers_out.content_length_n = ngx_strlen(ngx_hello_string);

    rc = ngx_http_send_header(r);
    
    if (rc == NGX_ERROR || rc > NGX_OK || r->header_only) {
        return rc;
    }

    return ngx_http_output_filter(r, out);
}


static char *
ngx_http_hello(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    ngx_http_core_loc_conf_t *clcf;

    clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_http_hello_handler;

    return NGX_CONF_OK;
}
