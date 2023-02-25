# UTC-SR01

Contient les codes de TD et de devoir de l'UV SR01 de l'Université de Technologie de Compiègne.
Tous les TD et devoirs sont réalisés en C.

Afin d'ouvrir les sujets, il faut les ouvrir sur un navigateur web.
Les premiers sujets étant au format html.


## :card_index_dividers: - Arborescence du projet

```
.
├── README.md
├── LICENSE
├── Devoir
.   ├── DM1
.   .   ├── Rapport-DM1.pdf
.   .   ├── Sujet-DM1.pdf
.   .   ├── EX1
.   .   .   ├── EX1-prog1.c
.   .   .   ├── EX1-prog2.c
.   .   .   ├── EX1-prog3.c
.   .   .   ├── EX1-prog4.c
.   .   .   ├── EX1-prog5.c
.   .   .   └── EX1-prog6.c
.   .   ├── EX2
.   .   .   ├── main.c
.   .   .   ├── EX2.c
.   .   .   └── EX2.h
.   .   └── EX3
.   .       ├── main.c
.   .       ├── EX3.c
.   .       └── EX3.h
.   └── DM2
.       ├── Rapport-DM2.pdf
.       ├── Sujet-DM2.pdf
.       ├── EX1
.       .   └── Prog1.c
.       ├── EX2
.       .   └── devoir-2-a-22-sr-01
.       .       ├── decoupage_module
.       .       .       ├── explorer.c
.       .       .       ├── explorer.h
.       .       .       ├── main.c
.       .       .       ├── Makefile.mak
.       .       .       ├── MakefileOpt.mak
.       .       .       ├── my_system.c
.       .       .       ├── my_system.h
.       .       .       ├── nbr_premiers.txt
.       .       .       ├── premier.c
.       .       .       └── premier.h
.       .       ├── nbr_premiers.txt
.       .       ├── Prog_premiers.c
.       .       ├── Prog_premiers_m1.c
.       .       ├── Prog_premiers_m2.c
.       .       ├── Prog_premiers_m3.c
.       .       └── README.md
.       └── EX3
.       .       ├── ApplicationManager.c
.       .       ├── get_time.c
.       .       ├── list_appli.txt
.       .       ├── mise_en_veille.txt
.       .       ├── network_manager.c
.       .       └── power_manager.c
.       └── ressources_initiales_fournies
.               ├── get_time.c
.               ├── list_appli.txt
.               ├── mise_en_veille.txt
.               ├── network_manager.c
.               ├── power_manager.c
.               └── time_manager.c
└── TD
    ├── Partie-1
    .   ├── TD1
    .   .   ├── Sujet-TD1.html
    .   .   ├── ex1a.c
    .   .   ├── ex1b.c
    .   .   ├── ex2.c
    .   .   ├── hello.c
    .   .   ├── hello2.c
    .   .   ├── pgcd.c
    .   .   └── TD1-notes
    .   ├── TD2
    .   .   ├── Sujet-TD2.html
    .   .   ├── ex2.c
    .   .   ├── ex2.h
    .   .   ├── ex4.c
    .   .   ├── ex4.h
    .   .   ├── ex5.c
    .   .   ├── ex5.h
    .   .   └── main.c
    .   ├── TD3
    .   .   ├── Sujet-TD3.html
    .   .   ├── ex1a.c
    .   .   ├── ex1b.c
    .   .   ├── ex2.c
    .   .   ├── ex3a.c
    .   .   ├── ex3b.c
    .   .   └── ex4.c
    .   ├── TD4
    .   .   ├── Sujet-TD4.html
    .   .   ├── main.c
    .   .   ├── ex1.c
    .   .   ├── ex2a.c
    .   .   ├── ex2b.c
    .   .   ├── ex3a.c
    .   .   ├── ex3b.c
    .   .   ├── ex4.c
    .   .   └── ex5.c
    .   ├── TD5
    .   .   ├── Sujet-TD5.html
    .   .   ├── EX1.c
    .   .   ├── main.c
    .   .   ├── main_ex2.c
    .   .   ├── mystr.c
    .   .   └── mystr.h
    .   └── TD6
    .       ├── Sujet-TD6.md
    .       ├── makefile
    .       ├── makefile-1
    .       ├── makefile-2
    .       ├── makefile-3
    .       ├── mystrchrn.c
    .       ├── mystrchrn.h
    .       ├── mystrinv.c
    .       ├── mystrinv.h
    .       ├── mystrshow.c
    .       ├── mystrshow.h
    .       └── teststring.
    ├── Partie-2
    .   ├── TD7
    .   .   ├── closep.c
    .   .   ├── closep1.c
    .   .   ├── closep2.c
    .   .   ├── ex1.c
    .   .   ├── EX3.c
    .   .   ├── EX4-arg1.c
    .   .   ├── EX4-arg2.c
    .   .   ├── EX5-code
    .   .   ├── EX5.c 
    .   .   ├── HELLO-code
    .   .   ├── Sujet-TD7.html
    .   .   └── toto.txt
    .   ├── TD8
    .   .   ├── closep.c
    .   .   ├── ecrific.c
    .   .   ├── ecrific10.c
    .   .   ├── f1.c
    .   .   ├── f2.c
    .   .   ├── f3.c
    .   .   ├── f4.c
    .   .   ├── Sujet-TD8.html
    .   .   └── titi.txt
    .   ├── TD9
    .   .   ├── fop.c
    .   .   ├── foprw.c
    .   .   ├── freop.c
    .   .   ├── pipe1.c
    .   .   ├── pipe2.c
    .   .   └── Sujet-TD9.html
    .   └── TD10
    .       ├── exec1.c
    .       ├── exec2.c
    .       ├── exec3.c
    .       ├── script.sh
    .       ├── sortie1.c
    .       ├── sortie2.c
    .       └── Sujet-TD10.pdf
    └── Partie-3
        └── TD11
            ├── Exercice-1
            ├── Exercice-2
            ├── Exercice-4
            ├── Sujet-TD11.pdf
            ├── tel.txt
            └── test_file.txt
```
## :technologist: - Langage utilisé
- C

## :memo: - Licence

[MIT](LICENSE)

## :notebook_with_decorative_cover: - Auteurs et contributeurs

-   **sacha-sz** - Tous les TD et DM - [sacha-sz](https://github.com/sacha-sz/)
-  **Th3o-D**  - Collaboration sur les DM - [Th3o-D](https://github.com/Th3o-D/)

## :bookmark_tabs: - Références
- **Lien moodle vers le cours**, (nécessite d'être connecté pour y accéder) : [UTC-SR01](https://moodle.utc.fr/course/view.php?name=SR01)
