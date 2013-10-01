
(*
dev:[grwlf@greyblade:~/proj/urbugs]$ LANG=C urweb -dbms sqlite AppMM
gcc  -pthread -Wimplicit -Werror -Wno-unused-value -I /home/grwlf/local/include/urweb  -c /tmp/webapp.c -o /tmp/webapp.o -g
/tmp/webapp.c:166:37: error: unknown type name 'uw_Basis_dml'
/tmp/webapp.c: In function 'uw_initializer':
/tmp/webapp.c:286:29: error: unknown type name 'uw_Basis_dml'
/tmp/webapp.c:287:30: error: initialization makes integer from pointer without a cast [-Werror]
/tmp/webapp.c:287:30: error: (near initialization for '__uwr___2') [-Werror]
/tmp/webapp.c:289:29: error: implicit declaration of function '__uwn_nodml_1384' [-Werror=implicit-function-declaration]
/tmp/webapp.c:295:31: error: unknown type name 'uw_Basis_dml'
/tmp/webapp.c:296:32: error: initialization makes integer from pointer without a cast [-Werror]
/tmp/webapp.c:296:32: error: (near initialization for '__uwr___3') [-Werror]
cc1: all warnings being treated as errors

/tmp/webapp.c included as AppMM_webapp.c
*)

fun anyway [t] (c : transaction t) : transaction {} = 
  x <- c ;
  return {}

table pagexx : {Id : int, Caption : string }
  PRIMARY KEY Id

fun nodml (q:dml) : transaction unit = 
  e <- dml q;
  return {}

task initialize = fn {} => 
  nodml (INSERT INTO pagexx(Id,Caption) VALUES (0,"Top"));
  nodml (INSERT INTO pagexx(Id,Caption) VALUES (1,"Top"));
  return {}


fun main {} = return <xml/>

