#include "/home/grwlf/local/include/urweb/config.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include <time.h>
 #include <sqlite3.h>
  #include "/home/grwlf/local/include/urweb/urweb.h"
 
 static void uw_setup_limits() {
  }
  
  void uw_global_custom() {
   uw_setup_limits();
   }
   typedef struct {
    sqlite3 *conn;
     } uw_conn;
    
    static void uw_client_init(void) {
    uw_sqlfmtInt = "%lld%n";
     uw_sqlfmtFloat = "%g%n";
     uw_Estrings = 0;
     uw_sql_type_annotations = 0;
     uw_sqlsuffixString = "";
     uw_sqlsuffixChar = "";
     uw_sqlsuffixBlob = "";
     uw_sqlfmtUint4 = "%u%n";
     }
    
    static void uw_db_validate(uw_context ctx) {
     uw_conn *conn = uw_get_db(ctx);
     sqlite3_stmt *stmt;
     int res;
     
     if (sqlite3_prepare_v2(conn->conn, "SELECT COUNT(*) FROM sqlite_master WHERE type = 'table' AND name = 'uw_AppMM_pagexx'", -1, &stmt, NULL) != SQLITE_OK) {
      sqlite3_close(conn->conn);
       uw_error(ctx, FATAL, "Query preparation failed:<br />SELECT COUNT(*) FROM sqlite_master WHERE type = 'table' AND name = 'uw_AppMM_pagexx'");
       }
      
      while ((res = sqlite3_step(stmt)) == SQLITE_BUSY)
      sleep(1);
       
      if (res == SQLITE_DONE) {
      sqlite3_finalize(stmt);
       sqlite3_close(conn->conn);
       uw_error(ctx, FATAL, "No row returned:<br />SELECT COUNT(*) FROM sqlite_master WHERE type = 'table' AND name = 'uw_AppMM_pagexx'");
       }
      
      if (res != SQLITE_ROW) {
      sqlite3_finalize(stmt);
       sqlite3_close(conn->conn);
       uw_error(ctx, FATAL, "Error getting row:<br />SELECT COUNT(*) FROM sqlite_master WHERE type = 'table' AND name = 'uw_AppMM_pagexx'");
       }
      
      if (sqlite3_column_count(stmt) != 1) {
      sqlite3_finalize(stmt);
       sqlite3_close(conn->conn);
       uw_error(ctx, FATAL, "Bad column count:<br />SELECT COUNT(*) FROM sqlite_master WHERE type = 'table' AND name = 'uw_AppMM_pagexx'");
       }
      
      if (sqlite3_column_int(stmt, 0) != 1) {
      sqlite3_finalize(stmt);
       sqlite3_close(conn->conn);
       uw_error(ctx, FATAL, "Table 'uw_AppMM_pagexx' does not exist.");
       }
      
      sqlite3_finalize(stmt);
      }
     
     static void uw_db_prepare(uw_context ctx) {
     uw_conn *conn = uw_get_db(ctx);
     
     }
    
    static void uw_db_init(uw_context ctx) {
    sqlite3 *sqlite;
    sqlite3_stmt *stmt;
    uw_conn *conn;
    
    if (sqlite3_open("App.db", &sqlite) != SQLITE_OK) uw_error(ctx, FATAL, "Can't open SQLite database.");
    
    if (uw_database_max < SIZE_MAX) {
    char buf[100];
     
     sprintf(buf, "PRAGMA max_page_count = %llu", (unsigned long long)(uw_database_max / 1024));
     
     if (sqlite3_prepare_v2(sqlite, buf, -1, &stmt, NULL) != SQLITE_OK) {
     sqlite3_close(sqlite);
      uw_error(ctx, FATAL, "Can't prepare max_page_count query for SQLite database");
      }
     
     if (sqlite3_step(stmt) != SQLITE_ROW) {
     sqlite3_finalize(stmt);
      sqlite3_close(sqlite);
      uw_error(ctx, FATAL, "Can't set max_page_count parameter for SQLite database");
      }
     
     sqlite3_finalize(stmt);
     }
    
    conn = calloc(1, sizeof(uw_conn));
    conn->conn = sqlite;
    uw_set_db(ctx, conn);
    uw_db_validate(ctx);
    uw_db_prepare(ctx);
    }
    
    static void uw_db_close(uw_context ctx) {
    uw_conn *conn = uw_get_db(ctx);
    sqlite3_close(conn->conn);
    }
    
    static int uw_db_begin(uw_context ctx) {
    uw_conn *conn = uw_get_db(ctx);
    
    if (sqlite3_exec(conn->conn, "BEGIN", NULL, NULL, NULL) == SQLITE_OK)
    return 0;
     else {
    fprintf(stderr, "Begin error: %s<br />", sqlite3_errmsg(conn->conn));
     return 1;
     }
    }
    static int uw_db_commit(uw_context ctx) {
    uw_conn *conn = uw_get_db(ctx);
    if (sqlite3_exec(conn->conn, "COMMIT", NULL, NULL, NULL) == SQLITE_OK)
    return 0;
     else {
    fprintf(stderr, "Commit error: %s<br />", sqlite3_errmsg(conn->conn));
     return 1;
     }
    }
    
    static int uw_db_rollback(uw_context ctx) {
    uw_conn *conn = uw_get_db(ctx);
    if (sqlite3_exec(conn->conn, "ROLLBACK", NULL, NULL, NULL) == SQLITE_OK)
    return 0;
     else {
    fprintf(stderr, "Rollback error: %s<br />", sqlite3_errmsg(conn->conn));
     return 1;
     }
    }
    
    
 
 static const char begin_xhtml[] = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\" lang=\"en\">";
 
 
  static char jslib[] = "";
  
  static uw_unit __uwn_initializer_1388(uw_context ctx, uw_unit __uwr___0)
   {
   return(0);
   }
  
  static uw_unit
   __uwn_expunger_1387(uw_context ctx, uw_Basis_client __uwr_cli_0)
   {
   return(0);
   }
  
  /* SQL table uw_AppMM_pagexx keys uw_id constraints   */
   
  
  static uw_unit
   __uwn_nodml_1384(uw_context ctx, uw_Basis_dml __uwr_q_0, uw_unit __uwr___1)
   {
   return(({
           uw_unit __uwr_e_2 =
           (uw_begin_region(ctx), ({
            char *dml = __uwr_q_0;
             
             uw_conn *conn = uw_get_db(ctx);
              sqlite3_stmt *stmt;
              
              if (sqlite3_prepare_v2(conn->conn, dml, -1, &stmt, NULL) != SQLITE_OK) uw_error(ctx, FATAL, "Error preparing statement: %s<br />%s", dml, sqlite3_errmsg(conn->conn));
              
              uw_push_cleanup(ctx, (void (*)(void *))sqlite3_finalize, stmt);
              
              int r;
               if ((r = sqlite3_step(stmt)) == SQLITE_BUSY) {sleep(1);
                                                              uw_error(ctx, UNLIMITED_RETRY, "Database is busy");
                                                              }
               
               if (r != SQLITE_DONE) uw_error(ctx, FATAL, "/home/grwlf/proj/urbugs/AppMM.ur:10:2-11:11: DML step failed: %s<br />%s", dml, sqlite3_errmsg(conn->conn));
               uw_pop_cleanup(ctx);
              
            
            uw_end_region(ctx);
            0;
            }));
           0;
           }));
   }
  
  
  static uw_unit
   __uwn_wrap_main_1386(uw_context ctx, uw_unit __uwr_x0_0, uw_unit __uwr___1)
   {
   return(0);
   }
 
 static int uw_input_num(const char *name) {
 return -1;}
 
 static uw_periodic my_periodics[] = {{NULL}};
 
 static int uw_check_url(const char *s) {
  return 0;
   }
  
 static int uw_check_mime(const char *s) {
  return 0;
   }
  
 static int uw_check_requestHeader(const char *s) {
  return 0;
   }
  
 static int uw_check_responseHeader(const char *s) {
  return 0;
   }
  
 static int uw_check_envVar(const char *s) {
  return 0;
   }
  
 extern void uw_sign(const char *in, char *out);
 extern int uw_hash_blocksize;
 static uw_Basis_string uw_cookie_sig(uw_context ctx) {
 uw_Basis_string r = uw_malloc(ctx, uw_hash_blocksize);
  uw_sign("", r);
  return uw_Basis_makeSigString(ctx, r);
  }
 
 static void uw_handle(uw_context ctx, char *request) {
 if (!strcmp(request, "/app.1380625231087.js")) {
 uw_Basis_string ims = uw_Basis_requestHeader(ctx, "If-modified-since");
  if (ims && !strcmp(ims, "Tue, 01 Oct 2013 11:00:31 GMT")) {
  uw_clear_headers(ctx);
   uw_write_header(ctx, uw_supports_direct_status ? "HTTP/1.1 304 Not Modified\r\n" : "Status: 304 Not Modified\r\n");
   return;
   }
  
  uw_write_header(ctx, "Content-type: text/javascript\r\n");
  uw_write_header(ctx, "Last-modified: Tue, 01 Oct 2013 11:00:31 GMT\r\n");
  uw_write_header(ctx, "Cache-Control: max-age=31536000, public\r\n");
  uw_write(ctx, jslib);
  return;
  }
 if (!strncmp(request, "/AppMM/main", 11) && (request[11] == 0 || request[11] == '/')) {
  request += 11;
  if (*request == '/') ++request;
  uw_write_header(ctx, "Content-type: text/html; charset=utf-8\r\n");
   uw_write_header(ctx, "Content-script-type: text/javascript\r\n");
   uw_write(ctx, begin_xhtml);
   uw_mayReturnIndirectly(ctx);
   uw_set_script_header(ctx, "");
   uw_set_needs_push(ctx, 0);
  uw_set_needs_sig(ctx, 0);
  uw_login(ctx);
  {
   uw_unit arg0 = uw_Basis_unurlifyUnit(ctx, &request);
    __uwn_wrap_main_1386(ctx, arg0, 0);
   uw_write(ctx, "</html>");
    return;
   }
   }
 uw_clear_headers(ctx);
 uw_write_header(ctx, uw_supports_direct_status ? "HTTP/1.1 404 Not Found\r\n" : "Status: 404 Not Found\r\n");
 uw_write_header(ctx, "Content-type: text/plain\r\n");
 uw_write(ctx, "Not Found");
 }
 
 static void uw_expunger(uw_context ctx, uw_Basis_client cli) {
  __uwn_expunger_1387(ctx, cli);
   }
 static void uw_initializer(uw_context ctx) {
 uw_begin_initializing(ctx);
  uw_end_initializing(ctx);
  ({
   uw_unit __uwr_$x_0 = 0, __uwr_$y_1 = 0;
   ({
    uw_unit __uwr___2 =
    (uw_begin_region(ctx), ({
                            uw_Basis_dml arg0 =
                             "INSERT INTO uw_AppMM_pagexx (uw_Caption, uw_Id) VALUES ('Top', 0)";
                             uw_unit arg1 = 0;
                            __uwn_nodml_1384(ctx, arg0, arg1);
                            }));
    uw_end_region(ctx);
     ({
      uw_unit __uwr___3 =
      (uw_begin_region(ctx), ({
                              uw_Basis_dml arg0 =
                               "INSERT INTO uw_AppMM_pagexx (uw_Caption, uw_Id) VALUES ('Top', 1)";
                               uw_unit arg1 = 0;
                              __uwn_nodml_1384(ctx, arg0, arg1);
                              }));
      uw_end_region(ctx);
       0;
      });
    });
   });
   __uwn_initializer_1388(ctx, 0);
    }
 uw_app uw_application = {1,
                            60,
                               "/",
                                   uw_client_init,
                                                  uw_initializer,
                                                                 uw_expunger,
                                                                             
                           uw_db_init,
                                      uw_db_begin,
                                                  uw_db_commit,
                                                               uw_db_rollback,
                                                                              
                           uw_db_close,
                                       uw_handle,
                                                 uw_input_num,
                                                              uw_cookie_sig,
                                                                            
                           uw_check_url,
                                        uw_check_mime,
                                                      uw_check_requestHeader,
                                                                             
                           uw_check_responseHeader,
                                                   uw_check_envVar,
                                                                   NULL,
                                                                        
                           my_periodics,
                                        "%c"};
 
