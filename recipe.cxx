#encoding "utf-8"   // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S      // указываем корневой нетерминал грамматики


Number -> AnyWord<wfl="[0-9]+[/,\\-]?[0-9]*">;
ShortMes -> 'мл' | 'г' | 'гр' | 'кг' |'л' (Punct) ;
ShortMesPart -> 'ч'| 'ст' (Punct);
MeasurementGen -> (Adj<gnc-agr[1]>) Noun<gnc-agr[1], gram='gen', rt>;
MeasurementNom -> (Adj<gnc-agr[1]>) Noun<gnc-agr[1], gram='nom', rt>;
AdjNoun -> (Adj<gnc-agr[1]>) Noun<gnc-agr[1], rt>;
Mes -> (ShortMesPart) AdjNoun;
Measurement -> Mes | ShortMes;
Product -> AdjNoun;
Ingredient -> Number interp (Ingredient.Quantity) (Measurement interp (Ingredient.Measurement)) Product interp (Ingredient.Product);


V -> Word<gram="imper"> | Word<gram="inf"> | Verb<GU=['1p','pl']> ;
AdjNounIns -> (Adj<gnc-agr[1]>) Noun<gnc-agr[1], gram='acc', rt>;
Action -> V interp (Step.Action::norm='inf');
AdjNounAcc -> (Adj<gnc-agr[1]>) Noun<gnc-agr[1], gram='acc', rt>;
N ->  AdjNounAcc interp (Step.Object::norm='acc')| Ingredient interp (Step.Object::norm='acc');
Object -> N interp (Step.Object::norm='acc');
AO -> Action Object;
OA -> Object Action;
Step -> (Object) Action (Object);

Period -> 'минута' | 'час' | 'секунда';
Time -> Number Period;

S -> Ingredient;
S -> Step;
S -> Step AnyWord* Time interp (Step.Time);

