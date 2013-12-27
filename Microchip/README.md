Ejemplos
=======

En este repositorio puedes encontrar una larga serie de ejemplos de las piezas de codigo que encontraras en el repositorio CodeBank8.

Es muy sencillo compilar estos ejemplos, te recomendamos clonar este repositorio en el mismo directorio en donde clonaste el repositorio codebank8

```
$ cd tu_repositorio
$ git clone http://github.com/hotboards/codebank8.git
$ git clone http://github.com/hotboards/examples.git
```

y eso seria todo, ahora solo tienes que habrir cada ejemplo con MPLABX, compilar y grabar mediante el bootloader en tu board pepper o si lo prefieres grabar directamente con algun programador.

En caso de que no tengan el mismo directorio ambos repositorios, tendras que modificar la ruta de inclusion en tu compilador.

```
MPLABX->Run->Set Project Configuration->Customize
```
en el recuadro de la izquierda selecciona la opcion ```mcc18``` y en el recuadro de la derecha en ```Include directories``` agrega las rutas al repositorio de codigo

```
<mypath_to>/codebank8
<mypath_to>/codebank8/bsp/Microchip
<mypath_to>/codebank8/middleware
<mypath_to>/codebank8/modules
```
una cosa mas, tendras que agregar de nuevo los archivos que no encuentre MPLABX :)

