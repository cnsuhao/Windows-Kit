Ejemplo SchemaImporterExtension Import Integer
=============================================
     Muestra c�mo escribir una instancia de la clase SchemaImporterExtension para importar los tipos de enteros del esquema XML como long y ulong en vez de como cadena.


Implementaciones de lenguaje del ejemplo
===============================
     El ejemplo est� disponible en las siguientes implementaciones de lenguaje:
     C#


Para generar el ejemplo mediante el s�mbolo del sistema:
=============================================
     1. Abra la ventana S�mbolo del sistema y vaya al directorio Technologies\Serialization\Xml Serialization\SchemaImporterExtension\ImportInteger.
     2. Escriba msbuild [nombre de archivo de la soluci�n].


Para generar el ejemplo mediante Visual Studio:
=======================================
     1. Abra el Explorador de Windows y vaya al directorio Technologies\Serialization\Xml Serialization\SchemaImporterExtension\ImportInteger.
     2. Haga doble clic en el icono del archivo .sln (soluci�n) para abrir el archivo en Visual Studio.
     3. En el men� Generar, seleccione Generar soluci�n.
     La aplicaci�n se generar� en el directorio \bin o \bin\Debug predeterminado.

     Otras cuestiones que se deben tener en cuenta al generar este ejemplo:
     1.  Escriba un nombre seguro para el ensamblado.
     2.  Agregue el ensamblado a la GAC
     3.  Agregue el ensamblado a machine.config en una secci�n schemas.xml.serialization/schemaImporterExtension


Para ejecutar el ejemplo:
=================
     1. Despl�cese hasta el directorio que contiene el nuevo ejecutable mediante el s�mbolo del sistema o el Explorador de Windows.
     2. Escriba [ExecutableFile] en la l�nea de comandos o haga doble clic en el icono de [SampleExecutable] para iniciarlo desde el Explorador de Windows.

     El ejemplo se puede generar con permiso limitado, pero para instalarlo es necesario disponer de privilegios de administrador puesto que el ensamblado debe agregarse a la GAC y es necesario modificar machine.config.

     Ejemplo de entrada en machine.config:

     system.xml.serialization
     	schemaImporterExtensions
     		add name="RandomString" type="Microsoft.Samples.Xml.Serialization.SchemaImporterExtension.ImportInteger, ImportInteger, Version=0.0.0.0, Culture=neutral, PublicKeyToken=3c3789dee90b3265"
     	schemaImporterExtensions
     system.xml.serialization


Comentarios
=================
     1.  Ejecute xsd.exe, wsdl.exe o Agregar referencia Web en WSDL que utilice xs:integer, xs:negativeInteger, xs:nonNegativeInteger, xs:positiveInteger o xs:nonPositiveInteger
2.  Observe que la clase generada utiliza long o ulong en vez de una cadena para los tipos de enteros del esquema XML

