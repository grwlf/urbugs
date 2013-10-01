
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

