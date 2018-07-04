Ejemplo ASPX Hosting
=======================
En este ejemplo se muestra c�mo combinar las caracter�sticas de HttpListener para crear un servidor Http que enrute las llamadas a la aplicaci�n Aspx alojada. La versi�n 2.0 de .NET Framework presenta la clase HttpListener generada sobre Http.Sys, que permite a los usuarios crear un servidor Http independiente.

En este ejemplo se utilizan las siguientes funciones de HttpListener:
1. Autenticaci�n
2. Habilitar SSL
3. Leer certificados de cliente sobre conexiones seguras


Implementaciones de lenguaje del ejemplo
===============================
     El ejemplo est� disponible en las siguientes implementaciones de lenguaje:
     C#


Para generar el ejemplo mediante el s�mbolo del sistema:
=============================================

     1. Abra la ventana S�mbolo del sistema de SDK y vaya al subdirectorio CS del directorio AspxHost.

     2. Escriba msbuild AspxHostCS.sln.


Para generar el ejemplo mediante Visual Studio:
=======================================

     1. Abra el Explorador de Windows y vaya al subdirectorio CS del directorio AspxHost.

     2. Haga doble clic en el icono del archivo .sln (soluci�n) para abrir el archivo en Visual Studio.

     3. En el men� Generar, seleccione Generar soluci�n.
     La aplicaci�n se generar� en el directorio \bin o \bin\Debug predeterminado.


Para ejecutar el ejemplo:
=================
     1. Despl�cese hasta el directorio que contiene el nuevo archivo ejecutable mediante el s�mbolo del sistema o el Explorador de Windows.
     2. Escriba AspxHostCS.exe en la l�nea de comandos o haga doble clic en el icono de AspxHostCS.exe para iniciarlo desde el Explorador de Windows. 


Comentarios
======================
1. Informaci�n de la clase

El archivo AspxHostCS.cs contiene la clase principal que crea y configura un agente de escucha y una aplicaci�n Aspx.

El archivo AspxVirtualRoot.cs contiene la clase que configura una clase HttpListener para escuchar en prefijos y esquemas de autenticaci�n compatibles.

El archivo AspxNetEngine.cs contiene la clase que configura una aplicaci�n Aspx asign�ndole un alias virtual que se asigna a un directorio f�sico.

El archivo AspxPage.cs contiene la clase que implementa la clase SimpleWorkerRequest y representa una p�gina solicitada por el cliente.

El archivo AspxRequestInfo.cs contiene la clase del contenedor de datos que se utiliza para pasar datos importantes desde HttpListenerContext a la aplicaci�n alojada.

El archivo AspxException.cs contiene la clase de excepci�n personalizada.

El directorio DemoPages contiene las p�ginas del ejemplo Aspx.


2. Uso del ejemplo
 
El archivo AspxHostCS.cs es la clase que contiene el m�todo principal que iniciar� una clase HttpListener y que configura un directorio f�sico como una aplicaci�n Aspx alojada. De manera predeterminada, la clase intenta configurar el directorio DemoPages (que se encuentra en el mismo directorio de ejemplos) como una aplicaci�n alojada bajo un alias virtual /.  Como la clase HttpListener de este ejemplo escucha en el puerto 80, es posible que tenga que detener IIS para ejecutar este ejemplo.

 
Cambiar el c�digo para uso individual: 

                //Crear un objeto AspxVirtualRoot con un puerto http y un puerto https si fuese necesario
                
                AspxVirtualRoot virtualRoot = new AspxVirtualRoot(80);


                //Configurar un directorio f�sico como alias virtual.

                //TODO: Sustituir el directorio f�sico por el directorio que se va a configurar.

		virtualRoot.Configure("/", Path.GetFullPath(@"..\..\DemoPages"));


                //TODO: Si es necesario agregar autenticaci�n, agregarla aqu�

                //virtualRoot.AuthenticationSchemes = AuthenticationSchemes.Basic;


3. Establecer el esquema de autenticaci�n
 
Despu�s de configurar un objeto AspxVirtualRoot, establezca el esquema de autenticaci�n necesario estableciendo el campo AuthenticationScheme en el objeto AspxVirtualRoot.

 
4. Habilitar Ssl
 

Para habilitar SSL, un certificado de servidor instalado en el almac�n de la m�quina debe estar configurado en el puerto en el que se requiere SSL. Para obtener m�s informaci�n sobre el modo de configurar certificados de servidor en un puerto mediante la utilidad Httpcfg.exe, consulte el v�nculo Httpcfg.

 
Nota: Winhttpcertcfg tambi�n se puede utilizar para configurar certificados de servidor en un puerto. Consulte el v�nculo Winhttpcertcfg.


Problema conocido
====================== 

Problema:
Cuando inicio la aplicaci�n aparece el siguiente mensaje de error:

"System.IO.FileNotFoundException: No se puede cargar el archivo o ensamblado 'AspxHostCS, Version=1.0.1809.19805, Culture=neutral, PublicKeyToken=null' ni una de sus dependencias. El sistema no encuentra el archivo especificado. Nombre del archivo: 'AspxHostCS, Version=1.0.1809.19805, Culture=neutral, PublicKeyToken=null'"

Soluci�n:
El archivo AspxHostCs.exe no est� en el directorio bin del directorio f�sico que se est� configurando. Copie el archivo AspxHostcs.exe en el directorio bin.


Vea tambi�n
============
Consulte la documentaci�n de las API de HttpListener y Aspx Hosting en el SDK de .NET Framework SDK y consulte tambi�n MSDN.
