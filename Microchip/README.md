Ejemplos
=======

**Estos ejemplos han sido migrados para el compilador XC8**

En este repositorio puedes encontrar una larga serie de ejemplos de las piezas de codigo que encontraras en el repositorio [CodeBank8](https://github.com/Hotboards/CodeBank8).

Es muy sencillo compilar estos ejemplos, te recomendamos descargar las versiones mas actuales de ambos repositorios (ve a sus respectivas secciones de Releases), descomprime ambos archivos y colocalos en el mismo directorio (recuerda cambiarle los nombres por los que aparecen a continuacion).

```
$ ls tu_directorio
CodeBank8
Examples
```

Y eso seria todo, ahora solo tienes que habrir cada ejemplo con MPLABX, compilar y grabar mediante el bootloader en tu board pepper.

En caso de que no tengan el mismo directorio ambos repositorios, tendras que modificar la ruta de inclusion en tu compilador.

```
MPLABX->Run->Set Project Configuration->Customize
```
en el recuadro de la izquierda selecciona la opcion ```XC8 compiler``` y en el recuadro de la derecha en ```Include directories``` agrega las rutas al repositorio de codigo

```
<mypath_to>/codebank8
<mypath_to>/codebank8/bsp/Microchip
<mypath_to>/codebank8/middleware
<mypath_to>/codebank8/modules
```
una cosa mas, tendras que agregar de nuevo los archivos que no encuentre MPLABX :)

