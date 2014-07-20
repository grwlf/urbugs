(*

$ urweb -dbms sqlite Submit
unhandled exception: Fail: Monoize: Action is not a closure

*)

con ct = [A = string, B = string]

type t = record ct


fun handler (x:$ct) : transaction page = return <xml><head/><body>{[x.A]}{[x.B]}</body></xml>

fun sbm {} : xml form ct [] = tag
    null
    None
    noStyle
    None
    {Value="aaaaa", Action=handler}
    (submit {})
    (cdata "")

fun main {} = return <xml><head/><body>
  <br/>
  <form>
  <textbox{#A}/>
  <textbox{#B}/>
  {sbm {}}
  </form>
  </body></xml>





