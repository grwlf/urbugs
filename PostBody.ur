(*
dev:[grwlf@ww:~/proj/urbugs]$ LANG=C urweb PostBody
gcc  -pthread -Wimplicit -Werror -Wno-unused-value -I /home/grwlf/local/include/urweb  -c /tmp/webapp.c -o /tmp/webapp.o -g
/tmp/webapp.c: In function '__uwn_wrap_api_1489':
/tmp/webapp.c:144:109: error: passing argument 2 of 'uw_Basis_htmlifyInt' makes integer from pointer without a cast [-Werror]
                                                                                                             __uwr_x2_2);
                                                                                                             ^
In file included from /home/grwlf/local/include/urweb/urweb.h:5:0,
                 from /tmp/webapp.c:8:
/home/grwlf/local/include/urweb/urweb_cpp.h:94:7: note: expected 'uw_Basis_int' but argument is of type 'uw_Basis_string'
 char *uw_Basis_htmlifyInt(struct uw_context *, uw_Basis_int);
       ^
cc1: all warnings being treated as errors
*)


fun api_1 (pb:postBody) (nm:string) : transaction page =
  return <xml>Processing the request</xml>

fun api (pb:postBody) (v:int) (nm:string) : transaction page =
  case v of
    |1 => api_1 pb nm
    |_ => error <xml>Version {[v]} is not supported</xml>
