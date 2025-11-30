Zaprojektuj i zaimplementuj system zamówień napojów w kawiarni, wykorzystując wzorzec projektowy Dekorator do dynamicznego dodawania składników i modyfikacji ceny.

Szczegóły:

1. Utwórz abstrakcyjną klasę bazową Napoj, która będzie zawierać czysto wirtualne metody getOpis() zwracającą opis napoju oraz getCena() zwracającą cenę. Klasa ta stanowi komponent bazowy wzorca Dekorator.

2. Zaprojektuj konkretne klasy napojów bazowych dziedziczące po Napoj: Espresso, Americano, Herbata. Każda klasa powinna zwracać odpowiedni opis i cenę bazową napoju.

3. Utwórz abstrakcyjną klasę DekoratorDodatku dziedziczącą po Napoj, która przechowuje wskaźnik (lub referencję) do obiektu typu Napoj. Klasa ta stanowi bazę dla wszystkich dekoratorów.

4. Zaimplementuj konkretne dekoratory reprezentujące dodatki: Mleko, BitaSmietana, SyropKarmelowy, PodwojnaKawa. Każdy dekorator powinien rozszerzać opis napoju o nazwę dodatku oraz doliczać odpowiednią kwotę do ceny.

5. W funkcji main() zademonstruj działanie wzorca:

	- Utwórz napój bazowy (np. Espresso)

	- Dodaj do niego kilka dekoratorów (np. mleko i syrop karmelowy)

	- Wyświetl pełny opis napoju wraz z końcową ceną

	- Pokaż, że dekoratory można łączyć w dowolnej kolejności i ilości

(Opcjonalnie) Zaimplementuj przechowywanie zamówień w std::vector<std::unique_ptr<Napoj>> i wyświetl podsumowanie wszystkich zamówień z łączną sumą do zapłaty.

Wymagania:

- Zastosuj inteligentne wskaźniki (std::unique_ptr lub std::shared_ptr) do zarządzania pamięcią

- Wykorzystaj polimorfizm i dynamiczne wiązanie metod

- Zadbaj o poprawną hierarchię dziedziczenia zgodną ze wzorcem Dekorator