Exemple ASPX Hosting
=======================
Cet exemple montre comment combiner les fonctionnalit�s de HttpListener pour cr�er un serveur Http qui route les appels vers l'application Aspx h�berg�e. La version 2.0 du .NET Framework introduit la classe HttpListener qui repose sur Http.Sys, ce qui permet aux utilisateurs de cr�er un serveur Http autonome.

Cet exemple utilise les fonctionnalit�s suivantes de HttpListener :
1. Authentification
2. Activation de SSL
3. Lecture des certificats clients sur des connexions s�curis�es


Langages d'impl�mentation de l'exemple
===============================
     Cet exemple est disponible dans les impl�mentations de langage suivantes :
     C#


Pour g�n�rer l'exemple � partir de l'invite de commandes
=============================================

     1. Ouvrez la fen�tre d'invite de commandes du SDK et acc�dez au sous-r�pertoire CS du r�pertoire AspxHost.

     2. Tapez msbuild AspxHostCS.sln.


Pour g�n�rer l'exemple � l'aide de Visual Studio
=======================================

     1. Ouvrez l'Explorateur Windows et acc�dez au sous-r�pertoire CS sous le r�pertoire AspxHost.

     2. Double-cliquez sur l'ic�ne du fichier solution (.sln) pour l'ouvrir dans Visual Studio.

     3. Dans le menu G�n�rer, s�lectionnez G�n�rer la solution.
     L'application sera g�n�r�e dans le r�pertoire par d�faut \bin ou \bin\Debug.


Pour ex�cuter l'exemple
=================
     1. Acc�dez au r�pertoire qui contient le nouveau fichier ex�cutable � l'aide de l'invite de commandes ou de l'Explorateur Windows.
     2. Tapez AspxHostCS.exe � l'invite de commandes ou double-cliquez sur l'ic�ne de AspxHostingCS.exe pour l'ex�cuter � partir de l'Explorateur Windows. 


Notes
======================
1. Informations de classe

Le fichier AspxHostCS.cs contient la classe principale qui cr�e et configure un �couteur et une application Aspx.

Le fichier AspxVirtualRoot.cs contient la classe qui configure un HttpListener pour �couter les pr�fixes et les sch�mas d'authentification pris en charge.

Le fichier AspxNetEngine.cs contient la classe qui configure une application Aspx en assignant un alias virtuel qui est mapp� � un r�pertoire physique.

Le fichier AspxPage.cs contient la classe qui impl�mente la classe SimpleWorkerRequest et repr�sente une page demand�e par le client.

Le fichier AspxRequestInfo.cs contient la classe conteneur de donn�es utilis�e pour passer les donn�es appropri�es de HttpListenerContext � l'application h�berg�e.

Le fichier AspxException.cs contient la classe d'exception personnalis�e.

Le r�pertoire Demopages contient les pages Aspx d'exemple.


2. Utilisation de l'exemple
 
Le fichier AspxHostCS.cs est la classe qui contient la m�thode principale qui lancera un HttpListener et configurera un r�pertoire physique sous la forme d'une application ASPX h�berg�e. Par d�faut, la classe essaie de configurer le r�pertoire DemoPages (qui se trouve dans le m�me r�pertoire samples) sous la forme d'une application h�berg�e sous alias virtuel /.  Dans la mesure o� HttpListener dans cet exemple �coute le port 80, il se peut que vous deviez arr�ter IIS pour ex�cuter cet exemple.

 
Modifiez le code pour votre utilisation personnelle : 

                //Cr�e un objet AspxVirtualRoot avec un port http et un port https si n�cessaire
                
                AspxVirtualRoot virtualRoot = new AspxVirtualRoot(80);


                //Configure un r�pertoire physique sous la forme d'un alias virtuel.

                //TODO : remplacez le r�pertoire physique par le r�pertoire � configurer.

		virtualRoot.Configure("/", Path.GetFullPath(@"..\..\DemoPages"));


                //TODO : Si l'authentification doit �tre ajout�e, ajoutez-la ici

                //virtualRoot.AuthenticationSchemes = AuthenticationSchemes.Basic;


3. D�finition du sch�ma d'authentification
 
Apr�s avoir configur� un objet AspxVirtualRoot, d�finissez le sch�ma d'authentification requis en d�finissant le champ AuthenticationScheme de l'objet AspxVirtualRoot.

 
4. Activation de Ssl
 

Pour activer SSL, un certificat de serveur install� dans le magasin de l'ordinateur doit �tre configur� sur le port qui requiert SSL. Pour plus d'informations sur la configuration d'un certificat de serveur sur un port � l'aide de l'utilitaire Httpcfg.exe, reportez-vous au lien Httpcfg.

 
Remarque : Winhttpcertcfg peut �galement �tre utilis� pour configurer le certificat de serveur sur un port.


Probl�me connu
====================== 

Probl�me :
Lorsque je d�marre l'application, le message d'erreur suivant s'affiche :

"System.IO.FileNotFoundException: Impossible de charger le fichier ou l'assembly 'AspxHostCS, Version=1.0.1809.19805, Culture=neutral, PublicKeyToken=null' ou une de ses d�pendances. Le syst�me ne trouve pas le fichier sp�cifi�. Nom de fichier : 'AspxHostCS, Version=1.0.1809.19805, Culture=neutral, PublicKeyToken=null'"

Solution :
Le fichier AspxHostCs.exe n'est pas pr�sent dans le r�pertoire bin du r�pertoire physique en cours de configuration. Copiez le fichier AspxHostcs.exe dans le r�pertoire bin.


Voir aussi
============
Consultez la documentation sur HttpListener et l'API Aspx Hosting dans la documentation du Kit de d�veloppement .NET Framework SDK et sur MSDN.

