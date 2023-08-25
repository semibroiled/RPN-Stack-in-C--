# RPN-Stack-in-C++

## Index

## Documentatoin in English
## Introduction

RPN (Reverse Polish Notation) or Postfix Notation, is a form of notation
in which we write mathematical expressions beginning with the operands or numbers
of the expression, ending with their operators.

For example, we would write `2+2`, which is in inline notation, as `2 2 +`, in 
Postfix Notation.

For more complex expressions, we don't use parentheses to denote order of operations
as in with normal inline notation. To compute postfix expressions, we follow along
a specific algorithms using a stack.

Inline Expressions are converted into RPN using the Stunting Yard Algorithm.

## 1. Computing RPN Expressions
### 1.1. Stacks

A stack is a type of ordered collection, where values are put in a piling order,
ie, following FILO principle. Imagine a pile of books on a desk. The first book at the
bottom would be the last you would get to, going top down to inspect every book.

Stacks across programming languages have some common operatoins.

You can pop, ie remove, the top level of a stack. In some languages,
pop would also read out the value to you. In the context of C++, these are two
distinct operations.

You can push, ie insert values onto the top level succesively. 

In C++, you can call a stack Data Type from the Standard Library.

### 1.2. RPN in Stack

Take the case of an RPN expressoin, 1 2 3 + -

To compute this expressions, you read from left to right.

Imagine you have an empty stack, where you can put in the values. Reading from 
left to write, if you see an integral or numerical value, you put the numbers in 
the stack. So, from the bottom up (remember, the values at the bottom level is
accessed last), you stack would read;

```
|------|---|
|top   | 3 |   
|......| 2 |  
|bottom| 1 | 
------------
```


At which point, we come to the operators. When we come across the first operator,
which is the + sign, we expel the top two operands- the numbers to be operated on,
from the stack. So, we would take out first 3, then 2, subsequently performing the operatoin
3+2. The result is 5, and we put it back in the stack. We repeat this with the -
operator. We get the top two values in the stack, being 5 and 1 repectively.
1-5 computed is -4. This is our final result.

At the end of postfix notation, there are no more operators left, and we have
one value, the result, left on stack.

## 2. Using the program

### 2.1. Compiling and Running the Program in Terminal with GCC

#### 2.1.1. Compiling RPN Calculator in Command Line to build/bin/

The code is separated into 5 files. The script running the calculator is in the main.cpp file.
With a C++ compiler, such as GCC or Clang, compile the individual files *.cpp in the path `./src/`
in terminal. For this, I assume to be using a GCC compiler already in PATH on a Mac Computer.

Explained step by step,
1) Go to the path with the files in terminal in root directory `RPN Stack in C++`
2) Compile files into object files
2a)) Run `g++ -c src/rpn_caculator.cpp`, assuming you're in the root `.` directory
2b)) Run `g++ --std=c++17 c src/main.cpp`

Note: In general, best use -std=c++17 if any versioning errors pop up in build

This generates a `main.o` and `rpn_calculator.o` file in your root directory

3) Link the two files into an executable in the build/bin/ directory; `g++ -o build/bin/calc main.o rpn_calculator.o`

This makes a binary executable named calc in the specified path. This name can be anything.

4) Run the executable with `build/bin/calc` and follow through the instructions in program

At any time, 
- type in `exit` to quit the program from the terminal, 
- type in `help` for further instructions on how to operate the program. 
- type in `in` to change mode to Inline Expression Mode
- type in `post` or `rpn` to change mode to RPN Expression Mode

Here's an excerpt from the help files on running the program.

```
Welcome to the RPN Stack Calculator Project!

This is an example implementation of a Calculator with Postfix Notation,
also known as RPN implemented with a Stack in C++

Enter a valid expression. Current Mode: RPN
Type exit or e to to quit. Type help or h to get additonal instructions.
>>h

Some Instructions to help you along the tool

Type in Mathematical Expressions using:
-> '+' for Addition,
-> '-' for Subtraction,
-> '/' for Division,
-> '*' for Multplication,
-> '^' for Exponent

The program runs either in RPN or Inline Mode
Type in Inline to switch to Inline mode,
or type in RPN to switch to RPN mode at any time

Expressions have to be in RPN or Postfix Notation when in RPN Mode;
You would write an inline expression 5+3 in RPN Notation as 5 3 +

Expressions have to be in Inline Notation when in Inline Mode;
You would write an inline expression >> 5 + 3
Inline expressions are converted into RPN before evaluation
Note that the expression tokens have to be separated by a space

Enter a valid expression. Current Mode: RPN
Type exit or e to to quit. Type help or h to get additonal instructions.
>>

```

Acceptable responses are space separated in postfix notation. 

_Examples are:_ 
- 5 4 +, 
- 5 9 1 + *,
- ...

Inline notation allows space separated entries with usage of only '(' adn ')'
as brackets. 

Normally, I would have already compiled the calc binary exectuable. So, 
steps 1 through 4 are done for you. And you would only need to do the 4th step
to hop into the executable.

#### 2.1.2. Compiling and Running Tests

The `src` directory also has a test file with which we can validate the efficacy of the program in the `RPNStackCalculator` Class. Here's how you can compile and run it yourself to test it.

In the `src/test_rpn_calculatpr.cpp` file, insert in your own expressions and values to test in `expressions` and `expectResults` array, defined in Line 9 and 19 respectively. By default, you can also work with the values there.

The steps are similar to compiling and linking the `main.cpp` file. 

Explained step by step,
1) Go to the path with the files in terminal in root directory `RPN Stack in C++`
2) Compile files into object files
2a)) Run `g++ -c src/rpn_caculator.cpp`, assuming you're in the root `.` directory.
This may already be done from 2.1.1.
2b)) Run `g++ -std=c++17 -c src/test_rpn_calculator.cpp`. This change with the `-std` is important, because at least in my computer, the `std::size` in Line 21 wouldn't compile otherwise.

This generates a `test_rpn_calculator.o` and `rpn_calculator.o` file in your root directory

3) Link the two files into an executable in the build/bin/ directory; `g++ -o build/bin/test_calc test_rpn_calculator.o rpn_calculator.o`

This makes a binary executable named test_calc in the specified path. This name can be anything of your choice.

4) Run the executable with `build/bin/test_calc` and the assertion results print to terminal. In case of errors, you would see something going wrong. 

Normally, I would have already compiled the test_calc binary exectuable. So, 
steps 1 through 4 are done for you. And you would only need to do the 4th step
to hop into the executable.

As of implementing the Inline Functionality in current branch, the test cases 
are yet to be updated different format to test for edge cases. Most tests 
were done off repo in a prototyping file.

### 2.2. Compiling the program with Cmake and Make

Again, I am assuming this to be done on a Darwin Mac Computer. I expect it to be slightly modified on a Windows computer. Linux/Ubuntu should be the same.

1) Go to an appropriate directory in build. I usually build in `build/Debug`. If the directory isn't there, you can make a new named folder. 
2) If there are already CMake files in there, delete the cache to make a new one if that is necessary, or jump to step X.
3) From your path, `build/Debug`, `build/Release` or `build/Test`; run `cmake ../..`
- Basically, we're calling to the `CMakeLists.txt` file in the root directory, which contains build instructions. 
4) Once the build is done, and there are CMake files in your current directory, there would also be a `Makefile` file created.
5) Run `make` from that path, and the executables `rpn_calculator` and `test_calculator` will be created in the same directory
6) Run `./rpn_calculator` or `./test_calculator` to run the executables

I should have already built them on push to the repositary (under `build/Release` in circumstances).
Either run the Commands from Step 6 there, or run `build/Release/rpn_calculator` or test with `build/Release/test_calculator`.
### 2.3. Design Decisions

The program is built with five files in src:

1) main.cpp
2) rpn_calculator.cpp
3) rpn_calculator.h
4) func_operator.h
5) helpSheet.h
6) infixToPostfix.h
7) validateInput.h
8) test_rpn_calculator.cpp

- in 2 and 3, we add a RPNStackCalculator Class to take on the repetitive operations into three method calls.A Stack Container is called in privately by the class whenever we declare an instance.

- in 4, we define an array of functions externally to check whether something is an operator, paranthesis, and also assign operator importance.

- in 5, we add in terminal output to help users in the terminal upon usage

- in 6, we add in the functionality of changing notations from infix

- in 7, we define a function that checks for illegal characters in the expression with a high degree of modularity

- in 1, the whole porgram is expose as an endpoint CLI 

- in 8, we define some simple assertions tests to inspect edge cases and bugs

##### Some Closing Remarks

We parse our input string and call on the methods to run the Calculator.

Basic CLI Functionality is added in an infintie while loop with a bool switch.

The program is kept bare bones on purpose, as anything other than this would be 
needless overengineering. This has become quite the extensive and large build as is. 

The task is simple to begin with. I've nevertheless packed
everything into its own modular files to allow future work on this to be 
easy and error averse. As such, it can be expanded endlessly by, for example, adding more 
methods in the rpn_calculator header and .cpp file, or adding in more operations in the rpn_calculator.cpp
and func_operator.h file, etc.

Optimally I would make this file with Cmake to allow for better distribution, which I will
still try to add in. I opted to do this manually, which is possible but difficult, as VSCode isn't being cooperative(There are some glitched with lldb and GDB Debuggers and config files).

I've written the Readme in context of a Mac Darwin Development Environment.

Add any point, the commands help, quit helps the user get more bang for the buck out of this program.

Users can also change between Inline and RPN Notation. The expressions is evaluated in Postfix. Any Infix is converted to Postfix, when run on Inline mode. 

There is an extensive use of guard clauses to rule out edge cases and validate inputs, for example.

All in all, I think this project demonstrated good practice in code writing, linting, formatting, project management, unit testing, modular expansion, proper use of functional and OOP approaches. I consider this a success. 

## Dokumentation auf Deutsch 

## Einführung

Die RPN (Reverse Polish Notation) oder Postfix-Notation ist eine Form der Notation, bei der mathematische Ausdrücke beginnend mit den Operanden oder Zahlen des Ausdrucks geschrieben werden und mit ihren Operatoren enden.

Zum Beispiel würden wir `2+2`, was in der Inline-Notation ist, als `2 2 +` in der Postfix-Notation schreiben.

Bei komplexeren Ausdrücken verwenden wir keine Klammern, um die Reihenfolge der Operationen anzugeben, wie es bei der normalen Inline-Notation der Fall ist. Um Postfix-Ausdrücke zu berechnen, folgen wir einem spezifischen Algorithmus unter Verwendung eines Stapels.

Inline-Ausdrücke werden mithilfe des Shunting Yard-Algorithmus in RPN umgewandelt.

## 1. Berechnung von RPN-Ausdrücken
### 1.1. Stapel (Stacks)

Ein Stapel ist eine Art geordneter Sammlung, bei der Werte in einer stapelähnlichen Reihenfolge abgelegt werden, dh nach dem Prinzip "FILO" (First In, Last Out). Stellen Sie sich einen Stapel Bücher auf einem Schreibtisch vor. Das erste Buch unten wäre das letzte, das Sie erreichen würden, während Sie jedes Buch von oben nach unten inspizieren.

Stapel haben in verschiedenen Programmiersprachen gemeinsame Operationen.

Sie können den obersten Wert eines Stapels entfernen (auch als "pop" bezeichnet). In einigen Sprachen würde "pop" auch den Wert für Sie auslesen. Im Kontext von C++ handelt es sich um zwei verschiedene Operationen.

Sie können Werte nacheinander auf den Stapel legen (auch als "push" bezeichnet).

In C++ können Sie einen Stack-Datentyp aus der Standardbibliothek verwenden.

### 1.2. RPN im Stapel

Nehmen Sie den Fall eines RPN-Ausdrucks: 1 2 3 + -

Um diesen Ausdruck zu berechnen, lesen Sie von links nach rechts.

Stellen Sie sich vor, Sie haben einen leeren Stapel, in den Sie die Werte legen können. Beim Lesen von links nach rechts, wenn Sie einen ganzzahligen oder numerischen Wert sehen, legen Sie die Zahlen auf den Stapel. Wenn Sie also von unten nach oben lesen (denken Sie daran, dass die Werte auf der untersten Ebene zuletzt abgerufen werden), sieht Ihr Stapel so aus:


```
|------|---|
|top   | 3 |   
|......| 2 |  
|bottom| 1 | 
------------
```


An diesem Punkt gelangen wir zu den Operatoren. Wenn wir auf den ersten Operator stoßen, der das + Zeichen ist, entfernen wir die obersten beiden Operanden - die Zahlen, auf denen die Operation ausgeführt werden soll - aus dem Stapel. Wir nehmen zuerst 3 und dann 2 heraus und führen anschließend die Operation 3+2 aus. Das Ergebnis ist 5, und wir legen es wieder auf den Stapel. Dies wiederholen wir mit dem - Operator. Wir nehmen die beiden obersten Werte im Stapel heraus, nämlich 5 und 1. 1-5 ergibt -4. Dies ist unser Endergebnis.

Am Ende der Postfix-Notation gibt es keine weiteren Operatoren mehr, und wir haben einen Wert, das Ergebnis, das im Stapel verbleibt.

## 2. Verwendung des Programms

### 2.1. Kompilieren und Ausführen des Programms in der Terminal mit GCC

#### 2.1.1. Kompilieren des RPN-Rechners in der Befehlszeile zum Verzeichnis build/bin/

Der Code ist in 5 Dateien unterteilt. Das Skript, das den Rechner ausführt, befindet sich in der Datei main.cpp. Mit einem C++-Compiler wie GCC oder Clang können Sie die einzelnen Dateien *.cpp im Pfad `./src/` im Terminal kompilieren. In diesem Beispiel gehe ich davon aus, dass Sie auf einem Mac-Computer bereits einen GCC-Compiler im PATH verwenden.

Schritt für Schritt erklärt:
1) Navigieren Sie im Terminal zum Pfad mit den Dateien im Stammverzeichnis `RPN Stack in C++`.
2) Kompilieren Sie die Dateien in Objektdateien.
2a) Führen Sie `g++ -c src/rpn_calculator.cpp` aus, vorausgesetzt, Sie befinden sich im Stammverzeichnis `.`.
2b) Führen Sie `g++ --std=c++17 -c src/main.cpp` aus.

Hinweis: Verwenden Sie im Allgemeinen `-std=c++17`, wenn bei der Kompilierung Fehler aufgrund von Versionsinkompatibilitäten auftreten.

Dadurch werden eine `main.o`- und eine `rpn_calculator.o`-Datei im Stammverzeichnis erstellt.

3) Verknüpfen Sie die beiden Dateien zu einer ausführbaren Datei im Verzeichnis `build/bin/` mit dem Befehl `g++ -o build/bin/calc main.o rpn_calculator.o`.

Dadurch wird eine ausführbare Binärdatei mit dem Namen "calc" im angegebenen Pfad erstellt. Dieser Name kann beliebig sein.

4) Führen Sie die ausführbare Datei mit `build/bin/calc` aus und folgen Sie den Anweisungen im Programm.

Zu jeder Zeit:
- Geben Sie `exit` ein, um das Programm über die Befehlszeile zu beenden.
- Geben Sie `help` ein, um weitere Anweisungen zur Bedienung des Programms zu erhalten.
- Geben Sie `in` ein, um in den Inline-Ausdrucksmodus zu wechseln.
- Geben Sie `post` oder `rpn` ein, um in den RPN-Ausdrucksmodus zu wechseln.

Hier ist ein Auszug aus den Hilfedateien zur Ausführung des Programms:

```
Welcome to the RPN Stack Calculator Project!

This is an example implementation of a Calculator with Postfix Notation,
also known as RPN implemented with a Stack in C++

Enter a valid expression. Current Mode: RPN
Type exit or e to to quit. Type help or h to get additonal instructions.
>>h

Some Instructions to help you along the tool

Type in Mathematical Expressions using:
-> '+' for Addition,
-> '-' for Subtraction,
-> '/' for Division,
-> '*' for Multplication,
-> '^' for Exponent

The program runs either in RPN or Inline Mode
Type in Inline to switch to Inline mode,
or type in RPN to switch to RPN mode at any time

Expressions have to be in RPN or Postfix Notation when in RPN Mode;
You would write an inline expression 5+3 in RPN Notation as 5 3 +

Expressions have to be in Inline Notation when in Inline Mode;
You would write an inline expression >> 5 + 3
Inline expressions are converted into RPN before evaluation
Note that the expression tokens have to be separated by a space

Enter a valid expression. Current Mode: RPN
Type exit or e to to quit. Type help or h to get additonal instructions.
>>

```

Akzeptable Antworten sind durch Leerzeichen getrennte Werte in Postfix-Notation.

_Beispiele sind:_
- 5 4 +,
- 5 9 1 + *,
- ...

Die Inline-Notation erlaubt Einträge mit Leerzeichen und die Verwendung von `(` und `)` als Klammern.

Normalerweise hätte ich die `calc`-Binärdatei bereits kompiliert. Die Schritte 1 bis 4 sind bereits für Sie erledigt. Sie müssen nur den 4. Schritt ausführen, um zur ausführbaren Datei zu gelangen.

#### 2.1.2. Kompilieren und Ausführen von Tests

Das `src`-Verzeichnis enthält auch eine Testdatei, mit der Sie die Effektivität des Programms in der `RPNStackCalculator`-Klasse validieren können. Hier erfahren Sie, wie Sie sie selbst kompilieren und ausführen können, um das Programm zu testen.

In der Datei `src/test_rpn_calculator.cpp` fügen Sie Ihre eigenen Ausdrücke und Werte ein, um sie in den Arrays `expressions` und `expectResults` zu testen, die in Zeile 9 bzw. 19 definiert sind. Standardmäßig können Sie auch mit den Werten arbeiten, die dort angegeben sind.

Die Schritte sind ähnlich wie beim Kompilieren und Verknüpfen der Datei `main.cpp`.

Schritt für Schritt erklärt:
1) Navigieren Sie im Terminal zum Pfad mit den Dateien im Stammverzeichnis `RPN Stack in C++`.
2) Kompilieren Sie die Dateien in Objektdateien.
2a) Führen Sie `g++ -c src/rpn_calculator.cpp` aus, vorausgesetzt, Sie befinden sich im Stammverzeichnis `.`. Dies könnte bereits in Schritt 2.1.1 erledigt worden sein.
2b) Führen Sie `g++ -std=c++17 -c src/test_rpn_calculator.cpp` aus. Diese Änderung mit `-std` ist wichtig, da zumindest auf meinem Computer `std::size` in Zeile 21 andernfalls nicht kompiliert werden würde.

Dadurch werden eine `test_rpn_calculator.o`- und eine `rpn_calculator.o`-Datei im Stammverzeichnis erstellt.

3) Verknüpfen Sie die beiden Dateien zu einer ausführbaren Datei im Verzeichnis `build/bin/` mit dem Befehl `g++ -o build/bin/test_calc test_rpn_calculator.o rpn_calculator.o`.

Dadurch wird eine ausführbare Binärdatei mit dem Namen "test_calc" im angegebenen Pfad erstellt. Dieser Name kann beliebig sein.

4) Führen Sie die ausführbare Datei mit `build/bin/test_calc` aus, und die Ergebnisse der Überprüfungen werden in der Befehlszeile angezeigt. Im Falle von Fehlern sehen Sie, wenn etwas schief geht.

Normalerweise hätte ich die `test_calc`-Binärdatei bereits kompiliert. Die Schritte 1 bis 4 sind bereits für Sie erledigt. Sie müssen nur den 4. Schritt ausführen, um zur ausführbaren Datei zu gelangen.

Was die Implementierung der Inline-Funktionalität im aktuellen Branch betrifft, müssen die Testfälle noch auf ein anderes Format aktualisiert werden, um Randfälle zu testen. Die meisten Tests wurden außerhalb des Repositorys in einer Prototyping-Datei durchgeführt.

### 2.2. Kompilieren des Programms mit CMake und Make

Nochmals, ich gehe davon aus, dass dies auf einem Mac-Darwin-Entwicklungsumfeld durchgeführt wird. Ich erwarte, dass es auf einem Windows-Computer leicht modifiziert wird. Für Linux/Ubuntu sollte es gleich sein.

1) Gehen Sie zu einem geeigneten Verzeichnis im Verzeichnis "build". Normalerweise erstelle ich in `build/Debug`, `build/Release` oder `build/Test`. Wenn das Verzeichnis dort nicht existiert, können Sie einen neuen Ordner mit dem gewünschten Namen erstellen.
2) Wenn bereits CMake-Dateien vorhanden sind, löschen Sie den Cache, um bei Bedarf neue Dateien zu erstellen, oder fahren Sie mit Schritt X fort.
3) Von Ihrem Pfad `build/Debug`, `build/Release` oder `build/Test` aus führen Sie `cmake ../..` aus.
- Im Wesentlichen rufen wir die Datei "CMakeLists.txt" im Stammverzeichnis auf, die Build-Anweisungen enthält.
4) Sobald der Build abgeschlossen ist und CMake-Dateien in Ihrem aktuellen Verzeichnis vorhanden sind, wird auch eine Datei "Makefile" erstellt.
5) Führen Sie `make` von diesem Pfad aus aus, und die ausführbaren Dateien "rpn_calculator" und "test_calculator" werden im selben Verzeichnis erstellt.
6) Führen Sie `./rpn_calculator` oder `./test_calculator` aus, um die ausführbaren Dateien auszuführen.

Normalerweise hätte ich die Binärdateien bereits im Verzeichnis "build/Release" erstellt. Führen Sie entweder die Befehle aus Schritt 6 dort aus oder führen Sie `build/Release/rpn_calculator` aus oder testen Sie mit `build/Release/test_calculator`.

### 2.3. Designentscheidungen

Das Programm besteht aus fünf Dateien im Verzeichnis "src":

1) main.cpp
2) rpn_calculator.cpp
3) rpn_calculator.h
4) func_operator.h
5) helpSheet.h
6) infixToPostfix.h
7) validateInput.h
8) test_rpn_calculator.cpp

- In 2 und 3 fügen wir eine Klasse RPNStackCalculator hinzu, um die wiederholten Operationen in drei Methodenaufrufe zu übernehmen. Ein Stapelcontainer wird von der Klasse privat verwendet, wann immer wir eine Instanz deklarieren.

- In 4 definieren wir extern ein Array von Funktionen, um zu überprüfen, ob etwas ein Operator oder eine Klammer ist, und weisen auch die Wichtigkeit von Operatoren zu.

- In 5 fügen wir die Ausgabe im Terminal hinzu, um Benutzern bei der Verwendung im Terminal zu helfen.

- In 6 fügen wir die Funktionalität hinzu, von der Infix-Notation in Postfix umzuwandeln.

- In 7 definieren wir eine Funktion, die unzulässige Zeichen im Ausdruck mit einem hohen Maß an Modularität überprüft.

- In 1 wird das gesamte Programm als CLI-Endpunkt bereitgestellt.

- In 8 definieren wir einige einfache Assertions-Tests, um Randfälle und Fehler zu überprüfen.

##### Einige abschließende Bemerkungen

Wir analysieren unseren Eingabezeichenfolge und rufen die Methoden auf, um den Rechner auszuführen.

Die grundlegende CLI-Funktionalität ist in einer unendlichen Schleife mit einem boolschen Schalter enthalten.

Das Programm ist absichtlich minimalistisch gehalten, da alles andere überflüssige Überkonstruktionen wären. Es ist bereits ziemlich umfangreich und groß.

Die Aufgabe ist zu Beginn einfach. Dennoch habe ich alles in separate modulare Dateien verpackt, um zukünftige Arbeiten daran einfach und fehlerfrei zu gestalten. So kann es endlos erweitert werden, indem beispielsweise weitere Methoden in der Header-Datei rpn_calculator und .cpp-Datei hinzugefügt werden oder mehr Operationen in der rpn_calculator.cpp- und func_operator.h-Datei hinzugefügt werden usw.

Optimalerweise würde ich diese Datei mit CMake erstellen, um eine bessere Verteilung zu ermöglichen, was ich immer noch versuchen werde hinzuzufügen. Ich habe mich dafür entschieden, dies manuell zu tun, was möglich, aber schwierig ist, da VSCode nicht kooperiert (es gibt einige Probleme mit lldb- und GDB-Debuggern und Konfigurationsdateien).

Ich habe die Readme im Kontext einer Mac Darwin-Entwicklungsumgebung geschrieben.

Fügen Sie an jeder Stelle die Befehle "help", "quit" hinzu, um dem Benutzer in der Befehlszeile mehr Nutzen aus diesem Programm zu bieten.

Benutzer können auch zwischen Inline- und RPN-Notation wechseln. Der Ausdruck wird in Postfix ausgewertet. Jegliche Infix-Notation wird bei der Ausführung im Inline-Modus in Postfix umgewandelt.

Es gibt eine umfangreiche Verwendung von Guard-Klauseln, um Randfälle auszuschließen und Eingaben zu validieren, zum Beispiel.

Insgesamt denke ich, dass dieses Projekt eine gute Praxis im Schreiben von Code, Linting, Formatierung, Projektmanagement, Unittesting, modularer Erweiterung, ordnungsgemäßer Verwendung funktionaler und OOP-Ansätze demonstriert. Ich finde es ist gelungen.






