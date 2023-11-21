# TopoPyBox - proof of concept

```text
___________                    __________         __________              
\__    ___/___ ______   ____   \______   \___.__. \______   \ _______  ___
  |    | /  _ \\____ \ /  _ \   |     ___<   |  |  |    |  _//  _ \  \/  /
  |    |(  <_> )  |_> >  <_> )  |    |    \___  |  |    |   (  <_> >    < 
  |____| \____/|   __/ \____/   |____|    / ____|  |______  /\____/__/\_ \
               |__|                       \/              \/            \/
```

## How to execute

First Compile the C Code

```bash
  cd lib/build
  cmake ..
  make
```

Now the Python Scrips can use the C Code

### Manual Compiling

```bash
gcc -fPIC -shared -o compiledName.so uncompiledFile.c
```

### requirements

- make
- cmake
- ctypes

### Wie das programm in Matlab aufgerufen werden kann
- öffne in matlab den ordner wo sich die mex_aspect.c datei befindet
- führe folgenden befehle aus (kann auch alles kopiert werden, jedoch dann ohne ">" )
```bash
>mex mex_aspect.c
>inputArray = single([1, 2, 3; 4, 5, 6]);  % Beispiel-Eingabematrix
>rows = size(inputArray, 1);
>cols = size(inputArray, 2);
> %Aufruf der Funktion
>outputArray = mex_aspect(inputArray, rows, cols);
> %Anzeigen der Ausgabematrix
>disp(outputArray);
```
- jetzt sollte hello world erscheinen und ein paar unötige nullen, weile nix berechnet wurde
