#encoding "utf-8"  
#GRAMMAR_ROOT S     


Number -> AnyWord<wfl="[0-9]+[/,\\-]?[0-9]*">;
ShortMes -> 'мл' | 'г' | 'гр' | 'кг' |'л' ;
ShortMesDot -> ShortMes ('.') ;

ShortMesPart -> 'ч'| 'ст';
ShortMesPartDot -> ShortMesPart ('.');

AdjNoun -> (Adj<gnc-agr[1]>) Noun<gnc-agr[1], rt>;
MesPart -> (ShortMesPartDot) AdjNoun;
Measurement -> MesPart | ShortMesDot;
Ingredient -> Number interp (Ingredient.Quantity) (Measurement interp (Ingredient.Measurement)) AdjNoun interp (Ingredient.Product);


V -> Word<gram="imper"> | Word<gram="inf"> | Verb<GU=['1p','pl']> ;
Action -> V interp (Step.Action::norm='inf');

AdjNounAcc -> (Adj<gnc-agr[1]>) Noun<gnc-agr[1], gram='acc', rt>;
NP ->  AdjNounAcc interp (Step.Object::norm='acc')| Ingredient interp (Step.Object::norm='acc');
Object -> NP interp (Step.Object::norm='acc');

AO -> Action Object;
OA -> Object Action;
Step -> (Object) Action (Object);

Period -> 'минута' | 'час' | 'секунда';
Time -> Number Period;

S -> Ingredient;
S -> Step;
S -> Step AnyWord* Time interp (Step.Time);


