
datatype dat a b = Con1 of a | Con2 of b

con hyperdat = fn x::(Type * Type)  => dat x.1 x.2

fun build1 [t1] [t2] (r:(t1*t2)) : hyperdat (t1,t2) = case r of (a,b) => Con1 a
val a1 = build1 (3,"abc")

(*
$ urweb -dbms sqlite Dat1 
Dat1.ur:9:34: (to 9:35) Wrong kind
Constructor:  t
  Have kind:  (Type * Type)
    Need kind:  Type
    Incompatible kinds
    Kind 1:  (Type * Type)
    Kind 2:  Type
*)
fun build2 [t ::: (Type*Type)] (r:t) : hyperdat t = case r of (a,b) => Con1 a
val a2 = build2 (3,"abc")

(*
$ urweb -dbms sqlite Dat1
Dat1.ur:13:15: (to 13:21) Substitution in constructor is blocked by a too-deep unification variable
Replacement:  <UNIF:V::(Type * Type)>
       Body:
       (UNBOUND_REL0.1 * <UNIF:Q::Type>) ->
        dat UNBOUND_REL0.1 UNBOUND_REL0.2
*)
(* fun build3 [t] r : hyperdat t = case r of (a,b) => Con1 a *)
(* val a3 : dat int string = build3 (3,"abc") *)

fun main {} : transaction page = return <xml/>
