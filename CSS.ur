
fun mkcss (n:string) (v:string) : (css_style -> css_style) = fn x => oneProperty x (value (property n) (atom v))

fun css (l : list (css_style -> css_style)) : css_style = 
  List.foldr (fn f s => f s) noStyle l

val cs = css (mkcss "position" "relative" :: [])

fun main {} :transaction page = return <xml><head/><body><p style={cs}>bla</p></body></xml>
