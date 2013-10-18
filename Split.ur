
fun split (i:int) : transaction {Client : unit -> transaction unit, Server : xbody} =
  let
    val s = <xml><p>the number is {[i]}</p></xml>
    val c = fn {} => alert(show i) ; return {}
  in
    return {Client = c, Server = s}
  end

fun main {} = 
  p <- split 5;
  return
    <xml>
      <head/>
      <body onload={p.Client {}}>
        {p.Server}
      </body>
    </xml>
