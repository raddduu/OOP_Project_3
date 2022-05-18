# OOP_Project_3

In acest proiect s-au folosit notiunile de template si design pattern. Pentru a le ilustra se foloseste un scenariu ipotetic al unei gradini zoologice.

Clasele cu care se lucreaza sunt animal(clasa de baza) si lion,monkey si cameleon(clasele derivate din baza). Clasa animal stocheaza informatiile de baza ale oricarui
animal: numele sau, varsta in ani si greutatea in kilograme. In claselederivate se stocheaza informatii specifice fiecarui animal in functie de specie (leii au gen
si statut in haita, maimutele au gen si numar de banane consumate in fiecare zi si cameleonii au numarul de culori pe care le pot lua).

Clasa template folosita este cea de database, scopul ei fiind sa simuleze o baza de date rudimentara. Aceasta este facuta special pentru obiecte derivate din
clasa animal deoarece foloseste o metoda ce ia ca parametru un obiect de tip animal. Ea poate realiza urmatoarele operatii: sa adauge un nou animal,
sa stearga un animal si sa afiseze continutul curent. Ilustrarea functionalitatii acesteia este verificata cu ajutorul unui meniu interactiv folosit in main.

Cele doua design pattern-uri folosite sunt singletone si facade, adaptate pe contextul gradinii zoologice.

Singletone se foloseste definind clasa zoo_manager care are o instanta unica. Aceasta reprezinta realitatea, deoarece o gradina zoologica are un singur manager.
In acest sens am constructorul este privat si exista o metoda statica ce instantiaza o singura data in cazul in care nu s-a realizat deja instantierea.
De asemenea, retinem numele si salariul managerului si se pot modifica ulterior, insa tot acelasi obiect ramane, dovedit prin faptul ca adresa din memorie
ramane constanta, indiferent de modificarile aduse datelor.

Facade se foloseste definind clasa zoo_facade. Aceasta gestioneaza reactia animalelor la un anumit fel de mancare oferit de zoo. Avantajul acesteia este faptul ca, per
total, codul devine mai lizibil si reactia animalelor devine mai usor de observat.
