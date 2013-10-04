
(*

dev:[grwlf@greyblade:~/proj/urbugs]$ urweb -version
The Ur/Web compiler, version 20130421 + dd40104e7175 qbase/qtip/script-tag/tip

dev:[grwlf@greyblade:~/proj/urbugs]$ urweb -dbms sqlite CSS
/home/grwlf/proj/urbugs/CSS.ur:2:64: (to 2:65) Anonymous function remains at code generation
Function:  (fn x : FFI(Basis.string) => x ^ "position: relative;")
:0:0: (to 0:0) Anonymous function remains at code generation
Function:  (fn _ : {} => write(UNBOUND_1))

*)

fun mkcss (n:string) (v:string) : (css_style -> css_style) = fn x => oneProperty x (value (property n) (atom v))

fun css (l : list (css_style -> css_style)) : css_style = 
  List.foldr (fn f s => f s) noStyle l

val cs = css (mkcss "position" "relative" :: [])

fun main {} :transaction page = return <xml><head/><body><p style={cs}>bla</p></body></xml>
