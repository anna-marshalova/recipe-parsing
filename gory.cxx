#encoding "utf-8"   // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S      // указываем корневой нетерминал грамматики
 

ProperName ->  Word<h-reg1>+;
Mountain -> 'пик'|'гора';
MountainName -> Mountain ProperName;
MountainChainName -> ProperName<gnc-agr[1]> 'гора'<gnc-agr[1], gram='pl', rt>;

Highest -> 'высокий'<gram='supr'>|'основной';

HighestPeak -> Highest<gnc-agr[2]> 'вершина'<gnc-agr[2], rt>;
Meter -> 'м'('.')|'метр';
Height -> AnyWord<wfm=/[0-9]{1,5}/> Meter;

Is -> 'считаться'|'–';
S -> HighestPeak MountainChainName<gram='gen'> interp (MountainChain.Name::norm='pl') Is MountainName interp (MountainChain.HighestPeak) AnyWord* Height interp (MountainChain.HighestPeakHeight);


