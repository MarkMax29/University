În inima unei păduri magice, 500 de creaturi fantastice — dragoni înțelepți 🐲, elfi sprinteni 🧝‍♂️, broaște șamanice 🐸, șoareci curajoși 🐭 și pisici telepate 🐱 — participă la o competiție legendară:
✨Marea Vânătoare de Comori din Pădurea Fermecată ✨
Fiecare creatură are voie să coopereze cu alte creaturi pentru a parcurge traseul misterios până la comoara ascunsă 💎. Unele legături de prietenie sunt mai solide 🫱🏼‍🫲🏾, altele doar de formă 🫠, dar toate sunt păstrate cu grijă într-un...
📜🔮 Registru Fermecat al Cooperărilor codificat de catre spiridusi
 
Acesta conține:
📘 Prima linie:
O singură etichetă, de forma:
[NumeCodificat123]
Aceasta ascunde numărul total n de creaturi. Pentru a-l afla, trebuie să:
🔑 Regulă magică pentru n:
Numărul total de creaturi este suma tuturor cifrelor prime care apar în prima linie.
Exemplu:
Linie: "Flame492" → Cifre: 4, 9, 2 → Prime: 2 → n = 2

📘 Următoarele linii:
Sunt de forma:
[C1] ajută [C2] cu runa [R]
Unde:
	•	[C1] și [C2] sunt coduri alfanumerice formate din exact 3 caractere.
	•	[R] este un număr între 1 și 999, care criptează eficiența colaborării.
🔑 Reguli pentru a decoda o linie:
🧙‍♂️ 1. Cine sunt C1 și C2?
	•	Se calculează:
x = (ASCII(C1[0]) + ASCII(C1[1]) + ASCII(C1[2])) % n + 1
y = (ASCII(C2[0]) + ASCII(C2[1]) + ASCII(C2[2])) % n + 1
(Numerele creaturilor sunt de la 1 la n)
✨ 2. Care este eficiența colaborării?
	•	v = (R % 17) + 1

🧪 Exemplu Registru :
Magic739
a1B ajută c3D cu runa 34
Z9x ajută M7k cu runa 212
fQ2 ajută wEr cu runa 17
bT5 ajută a1B cu runa 999
Rezumat decodare:
	•	Total creaturi: 10
	•	Relații ajutor și eficiență:
	◦	Creatura 3 → Creatura 9 (eficiență 1)
	◦	Creatura 8 → Creatura 10 (eficiență 9)
	◦	Creatura 4 → Creatura 3 (eficiență 1)
	◦	Creatura 6 → Creatura 3 (eficiență 14)
 
Creatura x 🧚‍♀️ a oferit ajutor creaturei y 🧝‍♂️, cu o valoare de cooperare v (cu cât mai mare, cu atât legătura e mai eficientă 💫).
⚠️ Ajutorul se oferă într-un singur sens: dacă un șoarece 🐭 îl ajută pe un dragon 🐲, dragonul nu e obligat să răspundă la fel. (Dar poate 😄)
 

💫 Cerințe magice pentru exploratori:
	1.	🔍 Găsiți pentru orice pereche de creaturi 🧌🦄 calea de colaborare cu eficiența totală maximă între ele.
(Adică: cum poate ajunge o bufniță la un dragon cooperând cu alți prieteni cât mai eficient?)
	2.	📦 Pentru două creaturi date (S și D, oferite ca parametri):
	◦	🧮 Afișați eficiența totală maximă a colaborării dintre ele.
	◦	🧵 Lista completă a ființelor intermediare prin care se transmite ajutorul.
	3.	🏆 Afișați creatura cu cele mai multe colaborări eficiente.
(a.k.a. Cea mai „populară” ființă din pădure 🐐💃)
	4.	👻 Detectați creaturile complet izolate (care nu ajută pe nimeni și nici nu primesc ajutor — spiriduși mai antisociali 😅).
	5.	🐯 Pentru creatura cu numărul 7, răspundeți la următoarele întrebări:
	◦	Cu cine poate coopera cel mai bine? 🤝
	◦	Cine îi oferă cel mai mare ajutor? 🎁
	◦	Poate ajunge la comoară? 🏁💰

🧙‍♀️ Hint magic:
„Nu toate comorile sunt ușor de găsit... Uneori, ajutorul vine de la cea mai mică broască 🐸 sau de la cel mai timid arici 🦔!”
 
🧙‍♂️ Mic indiciu de la Vrăjitorul Arborius:
„Cei care știu să vadă dincolo de cifre și să gândească în noduri și legături... vor fi primii care vor găsi comoara.” 🌌

🧠✨ Provocare pentru minți creative:
Transformă această lume fantastică într-o reprezentare care să poată fi înțeleasă de un... program C 😏. Gândește-te cum ai folosi tot ce știi despre drumuri, colaborări și legături eficiente pentru a naviga pădurea!
Gândește-te cum ai transpune tot acest registru magic într-o reprezentare cu liste de adiacență sau matrice, și ce algoritm ai putea folosi (poate un anume 🧝‍♂️ Floyd-Warshall? 🤔).
 
📜 Spor la magie și algoritmi! Happy hunting !
