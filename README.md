# proiect-sincretic

	Cerința pentru acest program este următoarea:

		Un grup de N țări trebuie reprezentate pe o hartă cu culori diferite, astfel încât oricare dintre acestea să fie colorată diferit de vecinii săi. Programul primește la intrare lista celor N țări (denumire, listă vecini), lista de culori posibile și determină culoarea pentru fiecare țară în parte.

	Eu am ales să fac acest program în C++:
		- Am creat o structură pentru țară, care conține denumirea țării, vecinii săi și culoarea atribuită acesteia.
		- Am construit funcția de colorare. În aceasta, primul for stochează în "folosita" culorile atribuite deja vecinilor (trecem prin toți vecinii și prin toate țările, iar dacă țara prin care trecem este vecină - cu țara pe care o colorăm - și are o culoare atribuită, acea culoare o inserăm în "folosita"). După, al doilea for trece prin toate culorile pentru a verifica dacă acestea au fost folosite deja pentru a colora vecinii, iar dacă nu a fost folosită, o utilizează pentru a colora țara. Am decis să amestec culorile după fiecare atribuire a uneia pentru o țară (folosind srand gestionez modificarea constantă a modului de amestecare a culorilor pe care random_shuffle o face, bazându-se pe timp).
		- În main, introducem numele și vecinii fiecărei țări, introducem culori, apelăm funcția pentru a le colora și le afișăm.
		- În cele din urmă, printr-un for, trecem prin toate țările pentru a verifica dacă li s-au atribuit culori (acest lucru se întâmplă deoarece nu au fost suficiente culori la dispoziție pentru a respecta cerința), ca în caz contrar să se afișeze mesajul de atenționare că nu sunt suficiente culori încât să se respecte cerința dată.

 
