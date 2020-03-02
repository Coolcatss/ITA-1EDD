# Les 5 - Voorbereiding

## Opgave 5.1 Dambord met stenen

### Onderdeel A
Maak een klasse `Dambord` volgens onderstaande specificatie. 

#### Instantievariabelen
Een dambord bevat een Array: stenen waarin vier damstenen zitten. Twee van deze stenen zijn zwart, twee wit. De positie en de diameter van de damstenen maakt niet uit als de diameter van elke steen maar gelijk is.

#### Methode
Een dambord heeft één methode: `tekenDamstenen` die alle damstenen die in de variabele stenen zit tekent.

Je kunt onderstaand klassendiagram gebruiken.

[![Klassendiagram Dambord](afbeeldingen/klassendiagram-dambord.png)

#### Antwoord
-----
```java
class Dambord {
  Damsteen[] stenen;

  Dambord(int aantal) {
    stenen = new Damsteen[aantal];
    int kleur;
    for (int i =0; i < stenen.length; i++) {
      if ( i < stenen.length/2) {
        kleur = 0;
      } else {
        kleur = #FFFFFF;
      }
      stenen[i] = new Damsteen((i*100)+ 200, 200, 50, kleur);
    }
  }
  void tekenDamstenen() {
    for (int i = 0; i < stenen.length; i++) {
      stenen[i].tekenDamsteen();
    }
  }
}
```

### Onderdeel B
Test de klasse `Dambord` met bijbehorende methode `tekenDamstenen` in het hoofdprogramma.

#### Antwoord
-----
```java

Dambord bord;
int aantal;
void setup(){
  size(800, 800);
  background(#ff0000);
  aantal = 4;
  bord =  new Dambord(aantal);
  bord.tekenDamstenen();
}
```

## Opgave 5.2 Student op School
Gegeven onderstaande klassendiagram.
![Klassendiagram Student op school.png](afbeeldingen/klassendiagram-student-op-school.png)]

Met bijbehorende code:

#### Klasse School
```java
class School {
  String naam;
  
  School(String naam) {
    this.naam = naam;
  } 
}
```

#### Klasse Student
```java
class Student {
  String naam;
  int nummer;
  School school;
  
  Student(String naam, int nummer, School school) {
    this.naam  = naam;
    this.nummer = nummer;
    this.school = school;
  }
}
al opgelost.

```

#### Hoofdprogramma
```java
void setup() {
  School deSchool = new School("ICA");
  
  Student s1 = new Student("hanneke", 1, "ICA");
  Student s2 = new Student("femke", 2, "ICA");
}
```

De constructor van de klasse `Student` bevat een fout die vaak voorkomt en makkelijk verborgen blijft. Het datatype van de van de parameter `school` is onhandig, waardoor in regel 9 de fout ontstaat.

### Onderdeel A
Teken het geheugenmodel van het hoofdprogramma  op het moment dat deze regel 5 net heeft uitgevoerd.

*Upload deze als `geheugenmodel-1.png` naar deze folder, om deze in de img in onderstaand antwoord blok zichtbaar te krijgen. Je mag ook een foto maken (pas naam en/of extensie even aan naar `.jpg`).*

#### Antwoord
-----
![Geheugenmodel regel 5](geheugenmodel-1.png)

-----

### Onderdeel B
Leg op basis van deze schets uit wat er fout gaat.

#### Antwoord
-----
Dat voor elke student maken wij een new school van de class school.
en niet de school die we al eerder hebben gemaakt.

-----

### Onderdeel C
Lost onderstaande verbetering op regel 4 en 5 aan het hoofdprogramma de fout op?

#### Antwoord
-----
```java


void setup() {
  School deSchool = new School("ICA");
  
  Student s1 = new Student("hanneke", 1, deSchool);
  Student s2 = new Student("femke", 2, deSchool);
 
}
op opgelost.
-----

*Tags: referentievariabele, verschillende != dezelfde instantie*
