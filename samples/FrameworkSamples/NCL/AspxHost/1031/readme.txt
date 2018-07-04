ASPX Hosting-Beispiel
=====================
Dieses Beispiel zeigt, wie die Features von HttpListener kombiniert werden, um einen HTTP-Server zu erstellen, der Aufrufe an eine gehostete ASPX-Anwendung weiterleitet. Version�2.0 von .NET Framework f�hrt die HttpListener-Klasse ein, die auf "Http.Sys" aufgebaut ist, die Benutzern erm�glicht, einen eigenst�ndigen HTTP-Server zu erstellen.

Dieses Beispiel verwendet folgende Features von HttpListener:
1. Authentifizierung
2. Aktivieren von SSL
3. Lesen von Clientzertifikaten �ber sichere Verbindungen


Sprachimplementierungen dieses Beispiels
========================================
     Dieses Beispiel ist in den folgenden Programmiersprachen verf�gbar:
     C#


So erstellen Sie das Beispiel mithilfe der Eingabeaufforderung
==============================================================

     1. �ffnen Sie das SDK-Eingabeaufforderungsfenster, und wechseln Sie im Verzeichnis "AspxHost" zum Unterverzeichnis "CS".

     2. Geben Sie "msbuild AspxHostCS.sln" ein (ohne Anf�hrungszeichen).


So erstellen Sie das Beispiel mithilfe von Visual Studio
========================================================

     1. �ffnen Sie Windows Explorer, und wechseln Sie im Verzeichnis "AspxHost" zum Unterverzeichnis "CS".

     2. Doppelklicken Sie auf das Symbol f�r die SLN-Datei (Projektmappe), um die Datei in Visual Studio zu �ffnen.

     3. W�hlen Sie im Men� "Erstellen" die Option "Projektmappe erstellen" aus.
     Die Anwendung wird im Standardverzeichnis "\bin" oder "\bin\debug" erstellt.


So f�hren Sie das Beispiel aus
==============================
     1. Wechseln Sie mithilfe der Eingabeaufforderung oder in Windows Explorer zu dem Verzeichnis, das die neue ausf�hrbare Datei enth�lt.
     2. Geben Sie an der Befehlszeile "AspxHostCS.exe" ein, oder doppelklicken Sie in Windows Explorer auf das Symbol f�r "AspxHostingCS.exe", um die Datei zu starten. 


Hinweise
========
1. Klasseninformationen

Die Datei "AspxHostCS.cs" enth�lt die Hauptklasse, die einen Listener und eine ASPX-Anwendung erstellt und konfiguriert.

Die Datei "AspxVirtualRoot.cs" enth�lt die Klasse, die einen HttpListener so konfiguriert, dass er Pr�fixe und unterst�tzte Authentifizierungsschemas �berwacht.

Die Datei "AspxNetEngine.cs" enth�lt die Klasse, die eine ASPX-Anwendung konfiguriert, indem ein virtueller Alias zugeordnet wird, dem ein physikalisches Verzeichnis zuordnet ist.

Die Datei "AspxPage.cs" enth�lt die Klasse, die die SimpleWorkerRequest-Klasse implementiert und eine vom Client angeforderte Seite darstellt.

Die Datei "AspxRequestInfo.cs" enth�lt die Datenhalterklasse, die verwendet wird, um wichtige Daten von HttpListenerContext an die gehostete Anwendung zu �bergeben.

Die Datei "AspxException.cs" enth�lt die benutzerdefinierte Ausnahmeklasse.

Das Verzeichnis "Demopages" enth�lt ASPX-Beispielseiten.


2. Verwendung des Beispiels
 
Die Datei "AspxHostCS.cs" ist die Klasse, die die Hauptmethode enth�lt, die einen HttpListener startet und ein physikalisches Verzeichnis als gehostete ASPX-Anwendung konfiguriert. Standardm��ig versucht die Klasse, das Verzeichnis "DemoPages" (das sich im selben Beispielverzeichnis befindet) als gehostete Anwendung unter dem virtuellen Alias / zu konfigurieren. Da HttpListener in diesem Beispiel den Anschluss�80 �berwacht, darf IIS dieses Beispiel m�glicherweise nicht mehr ausf�hren.

 
�ndern Sie den Code f�r die individuelle Verwendung:

                //Ein AspxVirtualRoot-Objekt mit einem HTTP-Anschluss und einem HTTPS-Anschluss erstellen, falls erforderlich.
                
                AspxVirtualRoot virtualRoot = new AspxVirtualRoot(80);


                //Ein physikalisches Verzeichnis als virtuellen Alias konfigurieren.

                //TODO: Ersetzen Sie das physikalische Verzeichnis durch das zu konfigurierende Verzeichnis.

		virtualRoot.Configure("/", Path.GetFullPath(@"..\..\DemoPages"));


                //TODO: Authentifizierung ggf. hier hinzuf�gen.

                //virtualRoot.AuthenticationSchemes = AuthenticationSchemes.Basic;


3. Festlegen des Authentifizierungsschemas
 
Legen Sie nach dem Konfigurieren eines AspxVirtualRoot-Objekts das erforderliche Authentifizierungsschema fest, indem Sie das AuthenticationScheme-Feld f�r das AspxVirtualRoot-Objekt festlegen.

 
4. Aktivieren von SSL
 

Zum Aktivieren von SSL muss ein im Computerspeicher installiertes Serverzertifikat auf dem Anschluss, auf dem SSL erforderlich ist, konfiguriert werden. Weitere Informationen �ber das Konfigurieren eines Serverzertifikats auf einem Anschluss mithilfe des Dienstprogramms "Httpcfg.exe" erhalten Sie �ber den Link f�r Httpcfg.

 
Hinweis: Winhttpcertcfg kann ebenfalls f�r das Konfigurieren eines Serverzertifikats auf einem Anschluss verwendet werden.


Bekannte Probleme
=================

Problem:
Wenn ich die Anwendung starte, wird folgende Fehlermeldung angezeigt:

"System.IO.FileNotFoundException: Die Datei oder Assembly "AspxHostCS, Version=1.0.1809.19805, Culture=neutral, PublicKeyToken=null" oder eine Abh�ngigkeit davon wurde nicht gefunden. Das System kann die angegebene Datei nicht finden. Dateiname: "AspxHostCS, Version=1.0.1809.19805, Culture=neutral, PublicKeyToken=null""

L�sung:
Die Datei "AspxHostCs.exe" ist im Verzeichnis "bin" des physischen Verzeichnisses, das konfiguriert wird, nicht vorhanden. Kopieren Sie die Datei "AspxHostcs.exe" in das Verzeichnis "bin".


Siehe auch
==========
Siehe auch API-Dokumentation zu HttpListener und ASPX Hosting in der .NET Framework SDK-Dokumentation und in MSDN.