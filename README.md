#Práctica 2 del laboratorio de Sistemas distribuidos

Aplicación con arquitectura cliente-servidor de una bitácora que agrega un nombre y la fecha en la que fue agregado a un archivo de texto, y busca en dicho archivo de texto el número de veces que aparece dicho nombre.

Esta aplicación fue hecha utiizando el framework RPCGen.

Para compilarlo, en una terminal se utiliza

	$ make -f ./Makefile.bitacora

Para correr el server, se utiliza el comando

	$ sudo ./suma_server

Finalmente, en una nueva terminal (que será el cliente), se pueden utilizar dos comandos, dependiendo si se desea agregar un nombre o si se quiere buscar un nombre:

-Para agregar un nombre:

	$ ./bitacora_client localhost add <nombre>

-Para buscar un nombre:

	$ ./bitacora_client localhost search <nombre>

EL archivo de texto generado se llama 'file.txt'.


