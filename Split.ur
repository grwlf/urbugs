
(*
[grwlf@greyblade ~/proj/urbugs ]$ urweb -dbms sqlite Split
/home/grwlf/proj/urbugs/Split.ur:5:21: (to 5:46) Server-side code uses client-side-only identifier "Basis.alert"

Formally, not a bug, but e feature. Still, very sad.
*)

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
