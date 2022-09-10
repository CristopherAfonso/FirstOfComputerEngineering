# Práctica 01. El Entorno de trabajo IaaS para la asignatura

### Objetivos

Los objetivos de esta práctica son:

* Realizar algunas tareas administrativas previas para facilitar el trabajo en la asignatura 
* Conocer y configurar el entorno de trabajo de la asignatura en el sistema Linux del IaaS 
* Ser capaz de usar comandos de la shell de GNU/Linux para trabajar en la Máquina Virtual (VM) de la asignatura
* Configurar y practicar el uso del Visual Studio Code para editar ficheros en su VM
* Editar, compilar y ejecutar `hello_world.cpp`

### Rúbrica de evaluacion del ejercicio
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva)
que se tendrán en cuenta a la hora de evaluar esta práctica:
* Se valorará positivamente que el alumnado haya realizado las tareas propuestas con anterioridad a la sesión de prácticas
* Se valorará la realización de las diferentes tareas que se proponen

Con anterioridad a la sesión de prácticas, debe Ud. estudiar los documentos que se enlazan desde
éste así como realizar todas las tareas posibles de las que en este documento se proponen.

### Tareas previas
#### GNU/Linux en su ordenador de trabajo
1. Para el trabajo en las prácticas de la asignatura se utilizará intensivamente el Sistema Operativo Linux,
trabajando fundamentalmente en una [máquina virtual](https://es.wikipedia.org/wiki/M%C3%A1quina_virtual) disponible a través de la infraestructura 
[IaaS](https://es.wikipedia.org/wiki/Infraestructura_como_servicio_(IaaS)) de la ULL.
Es por ello que resulta muy conveniente que el alumnado tenga instalado Linux en un ordenador personal con el que
trabaje desde su casa. 
Se optará preferentemente por la distribución Ubuntu para que sea la misma que tiene la máquina virtual de la asignatura.  
Hay al menos tres opciones para ello, que son las siguientes en orden de mayor a menor idoneidad para el trabajo en la asignatura:

  * Si dispone Ud. de un ordenador propio, de uso exclusivo, que pueda formatear (borrando por tanto toda la información)
  instale directamente Ubuntu en él siguiendo (por ejemplo) 
  [estas instrucciones](https://ubuntu.com/tutorials/install-ubuntu-desktop#1-overview). 
  Para esta instalación necesitará Ud. crear un pendrive desde el que pueda arrancar el ordenador. 
  Siga para ello (por ejemplo) 
  [estas otras instrucciones](https://ubuntu.com/tutorials/create-a-usb-stick-on-windows#1-overview).

  * Instalar Ubuntu como un sistema "invitado" dentro de Windows usando para ello un
  software de virtualización como VirtualBox. 
  La página [Install Ubuntu on Oracle VirtualBox](https://brb.nci.nih.gov/seqtools/installUbuntu.html)
  contiene las instrucciones a seguir para instalar Ubuntu como sistema invitado en Windows.
  
  * Utilizar WSL, [Windows subsystem for Linux](https://docs.microsoft.com/es-es/windows/wsl/install-win10).
  WSL es una característica introducida en Windows 10 que permite instalar un núcleo Linux directamente sobre el sistema operativo de Microsoft.

Las tres opciones anteriores están ordenadas atendiendo a la que consideramos idoneidad de cada una, siendo la primera la más idónea, pero este orden posiblemente coincide con el orden inverso de complejidad de la instalación: la primera es posiblemente más compleja que la tercera. 
Tenga esto en cuenta a la hora de decidirse por cualquiera de estas opciones.

Una opción alternativa que se considera menos adecuada consiste en no instalar un sistema Linux sino acceder 
a la máquina virtual IaaS de la asignatura desde Windows usando para ello un cliente ssh. 
Se recomienda para este caso instalar en Windows [el cliente ssh PuTTY](https://www.putty.org/) que puede Ud. descargar libremente.  
[Este vídeo](https://www.youtube.com/watch?v=_-rS8QM0JaI) muestra cómo configurar la VPN en Windows y cómo usar Putty para acceder a una máquina virtual.

En todo caso recuerde que si desea acceder a las máquinas de la Universidad desde fuera del campus
universitario necesitará Ud. configurar una conexión usando [VPN](https://es.wikipedia.org/wiki/Red_privada_virtual).
Para configurar la conexión VPN siga las instrucciones de la página [Servicio de VPN de la ULL](https://www.ull.es/servicios/stic/2016/05/10/servicio-de-vpn-de-la-ull/).  
Para conexiones VPN usando Windows ha de instalar la aplicación Global Protect tal como se explica en el documento
[Guía de configuración del cliente VPN GlobalProtect. Sistema Operativo Windows](https://drive.google.com/open?id=0B3mzWpxzbJD1Zm9TdmpXSV9mdGs).
[Esta imagen](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/3b0223eef4fff02835108ac59ea8d2f2f26c43cc/img/GlobalProtect.PNG)
muestra el establecimiento de la conexión VPN con la red de la ULL,
[esta otra](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/3b0223eef4fff02835108ac59ea8d2f2f26c43cc/img/GlobalProtect_InicioSesi%C3%B3n.PNG)
muestra el inicio de sesión y finalmente
[esta última](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/3b0223eef4fff02835108ac59ea8d2f2f26c43cc/img/GlobalProtect_Conectado.PNG)
muestra la conexión ya establecida.

[Este vídeo](https://youtu.be/ZHZ-R--fQ68) muestra cómo establecer en linux una conexión vpn y [este otro](https://www.youtube.com/watch?v=jHUfeN_NMYE&feature=youtu.be) muestra cómo conectar desde linux usando ssh con una máquina virtual del IaaS.

#### Dirección de correo alternativa
2. Acceda al [portal de gestión de usuarios](https://usuarios.ull.es/autogestion/cambio_alias/)
del Servicio TIC de la ULL y configure allí una dirección de correo electrónico alternativa a su dirección
`aluXXXX@ull.edu.es`.
Las direcciones (alias) alternativas que el sistema le ofrece han de incluir necesariamente dos dígitos
numéricos (sin significado específico alguno) y permiten que su dirección de correo sea más legible y fácil de
recordar, sobre todo para otras personas.
Podrá utilizar indistintamente las direcciones `aluXXXX@ull.edu.es` y el alias que configure.

#### GitHub
3. [GitHub](https://github.com/) es una plataforma de desarrollo colaborativo para alojar proyectos utilizando el sistema de control de versiones Git.
Cree una cuenta en [GitHub](https://github.com/join?ref_cta=Sign+up&ref_loc=header+logged+out&ref_page=%2F&source=header-home). 
Configure el perfil de esa cuenta de modo que incluya una imagen (fotografía) en la que se le reconozca y haga que la cuenta de e-mail asociada sea la dirección institucional o su alias.
Para la configuración de esa cuenta se le recomienda usar su nombre real, puesto que sus repositorios de código en GitHub
pasarán a formar parte de su curriculum profesional.

#### El editor Vim
4. Para editar algunos ficheros en esta sesión se usará el editor [vim](https://www.vim.org/).
Estudie los primeros pasos de [este tutorial](https://blog.desdelinux.net/usando-vim-tutorial-basico/) para que
aprenda lo básico sobre cómo modificar un fichero usando vi.
Con el estudio de este otro [tutorial interactivo on-line](https://www.openvim.com/) debe aprender lo mínimo que necesita
para usar vi en esta sesión.
Si está Ud. interesada/o en aprender vim (es un editor muy potente pero los comienzos son difíciles) dispone
de muchos tutoriales en la web. 
[Este tutorial](https://github.com/Izaird/Vim-primeros-pasos) explica lo básico de vim a través de ejemplos concretos con ficheros de texto.

Para editar algunas líneas concretas de un fichero de texto usando vi siga estas indicaciones:
* Use las teclas con flechas arriba/abajo para mover el cursor a la línea que desee editar.
* Antes de modificar el texto ha de presionar `i` para acceder al modo de inserción de vim.
* Cuando acabe de modificar el texto, pulse ESC (para salir del modo de inserción)
* Ahora escriba `:wq!` y presione ENTER para guardar los cambios en disco. W es para escribir (Write), Q para salir (Quit) y ! se usa para forzar la escritura.

### El Entorno ULL-IaaS
5. Estudie el documento 
[Manual de administración de Máquinas](https://docs.google.com/document/d/1nj-dxu7LXrNhj3ewCdfaPSc8OV4e_TYpGTQdK78YExY/edit).
Tenga en cuenta que el acceso a la infraestructura IaaS está ligado a que esté Ud. registrada/o en el Aula Virtual de la Asignatura.
Siga las instrucciones de ese documento para acceder a la [interfaz web de las máquinas IaaS](https://iaas.ull.es).

6. Inicie sesión en Linux en alguno de los PCs de una sala del Centro de Cálculo o bien desde otro ordenador usando VPN si lo hace desde fuera de la Universidad.
En este documento se denominará máquina remota a la máquina virtual (VM) del [IaaS-ULL](https://www.ull.es/servicios/stic/2015/10/27/nuevo-servicio-iaas/) 
y máquina local al PC en el que está Ud. trabajando.

7. Acceda a la [interfaz web](https://iaas.ull.es/ovirt-engine/sso/login.html) 
de la plataforma IaaS-ULL (recuerde tener iniciada una conexión VPN si trabaja desde fuera del campus universitario) y autentifíquese en esa interfaz con sus credenciales (username + password) de la cuenta institucional. 
[Esta imagen](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/3b0223eef4fff02835108ac59ea8d2f2f26c43cc/img/1-Ovirt-login.png)
muestra la pantalla de acceso a la interfaz.  
Vea el estado de la máquina y arránquela para comenzar a trabajar con ella.
[Esta imagen](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/3b0223eef4fff02835108ac59ea8d2f2f26c43cc/img/2-OvirtVMs.png)
muestra las máquinas virtuales disponibles. 
Inicialmente la máquina de la asignatura aparece con estado "Apagado" y se arranca mediante el botón "Ejecutar".  
El proceso de arranque de la máquina puede durar unos minutos.
Una vez que la máquina haya arrancado, tome nota de la Dirección IP de la máquina, que se muestra en el apartado "Detalles" de la máquina.
[Esta imagen](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/3b0223eef4fff02835108ac59ea8d2f2f26c43cc/img/5-ovirt-Direcci%C3%B3nIP.png)
muestra la pantalla de información correspondiente a una máquina virtual y en ella se muestra la dirección IP de la máquina.   
La [dirección IP](https://en.wikipedia.org/wiki/IP_address) es una secuencia de números (de la forma `10.6.131.106`) que identifican de forma unívoca a cualquier dispositivo conectado a Internet.
Esta dirección será necesaria para establecer conexiones directas a la máquina a través de ssh desde su casa o desde las salas del Centro de Cálculo de la ESIT. 
Anote esa dirección IP puesto que la máquina conserva esa dirección IP de forma estable. 
Si en algún momento **experimenta dificultades de conexión**, conecte a través de la interfaz web y compruebe que
la dirección de la máquina no ha cambiado.
Para consultar la IP de una máquina en un terminal Linux utilice el comando:
```
$ ifconfig -a
```
8. Abra una conexión ssh con su máquina usando la dirección IP de la misma que ha obtenido en el paso anterior.
Si esa conexión la realiza desde Linux el comando que ha de usar para establecerla es
```
$ ssh usuario@10.6.131.106
```
Cambiando en el comando anterior, la dirección IP por la de su máquina.
En cuanto se conecte a la máquina remota, el sistema le pedirá sus credenciales.
Recuerde que inicialmente esas credenciales de acceso son: Username - `usuario` y password - `usuario`.

**Preste mucha atención a este paso** porque si comete un error, puede ser irreparable y su máquina resultará inaccesible.
En este primer acceso el sistema le solicitará que introduzca la contraseña actual y que escriba dos veces la nueva contraseña elegida.
No se preocupe por ahora por la contraseña que elija puesto que siempre la puede cambiar en el futuro 
pero **anote** el password que elija para no perderlo u olvidarlo.
La recomendación es que elija ahora un password simple (algo como `informatica` o similar).
Ya en el futuro podrá cambiarlo por otro más robusto.
Compruebe a continuación el sistema operativo y versión del mismo:
```
$ lsb_release -a
```

9. Actualice el software (paquetes) de la máquina siguiendo las indicaciones de [esta página](https://linuxconfig.org/how-to-update-ubuntu-packages-on-18-04-bionic-beaver-linux) (por ejemplo).
Los comandos que tendrá que utilizar son:
```
$ sudo apt update
$ sudo apt upgrade
$ sudo apt autoremove
```
[Esta imagen](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/3b0223eef4fff02835108ac59ea8d2f2f26c43cc/img/update.png)
muestra el resultado de ejecución del primero de estos comandos y 
[esta otra](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/3b0223eef4fff02835108ac59ea8d2f2f26c43cc/img/upgrade2.png)
del segundo de ellos.    
Cuando el sistema le pregunte si hacerlo, indique No instalar `grub`.
Véase 
[esta imagen](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/3b0223eef4fff02835108ac59ea8d2f2f26c43cc/img/grub.png)
y 
[esta otra](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/3b0223eef4fff02835108ac59ea8d2f2f26c43cc/img/grub2.png) 
que ilustran esas opciones.
Los comandos que se ejecutan con `sudo` se están ejecutando como "superusuario" de modo que **nunca** ejecute comandos con `sudo` salvo 
que sepa muy bien lo que está haciendo o se le indique (como en este caso) cómo usarlo.

10. Edite los ficheros necesarios para [cambiar el nombre lógico de la máquina](https://askubuntu.com/questions/9540/how-do-i-change-the-computer-name) que le ha sido asignada. 
Se propone utilizar como nombre algo como Ubuntu-18-ASIG-XXX (cambiando "ASIG" por el acrónimo de la asignatura y 
"XXX" por lo que Ud. quiera), aunque puede Ud. usar para su máquina el nombre que prefiera.
Para realizar ese cambio ha de editar Ud. los siguientes ficheros (necesita usar `sudo` para tener permisos de
root al tratarse de ficheros del sistema) y sustituir en ellos el nombre actual de la máquina (que es "ubuntu") por el que haya elegido:
```
$ sudo vi /etc/hostname
$ sudo vi /etc/hosts
```
Para que este cambio tenga efecto, ha de reiniciar la máquina.  
Siempre puede reiniciar la máquina desde la interfaz web de administración o bien usando el comando:
```
$ sudo reboot
```

#### git y GitHub
11. Instale `git` en su máquina:
```
$ sudo apt install git
```
y compruebe que está instalado:
```
$ git --version
```

12. Consiga que se pueda subir código desde su máquina virtual hacia su cuenta GitHub sin necesidad de autentificación. 
Consulte para ello las instrucciones
[Adding a new SSH key to your GitHub account](https://docs.github.com/en/enterprise/2.15/user/articles/adding-a-new-ssh-key-to-your-github-account)

13. Cree un directorio `practicas` y  clone en él un repositorio git:
```
cd
mkdir practicas
cd practicas
git clone git@github.com:fsande/IB-P01-EntornoIaaS.git 2019-2020-IB-P01-EntornoIaaS
```

#### Visual Studio Code
14. En la máquina local ejecute el Microsoft Visual Studio Code (VSC) y siga 
[estas instrucciones](https://code.visualstudio.com/docs/remote/ssh)
para configurar la edición remota de ficheros alojados en su máquina virtual.  
Para instalar VSC en la instalación Linux de su casa siga
[estas instrucciones](https://code.visualstudio.com/docs/setup/linux)
descargando el paquete `.deb`. 
Resulta útil realizar el paso 3 (opcional) del apartadto "SSH host setup#" que se muestra
[en esta página](https://code.visualstudio.com/docs/remote/troubleshooting#_configuring-key-based-authentication)
Ejecute para ello (sustituyendo la dirección IP por la de su VM):
```
$ ssh-keygen -t rsa -b 4096
$ export USER_AT_HOST=usuario@10.6.131.106
$ export PUBKEYPATH="$HOME/.ssh/id_rsa.pub"
$ ssh-copy-id -i "$PUBKEYPATH" "$USER_AT_HOST"
```
[Esta imagen](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/master/img/VSC-connect-to-host.png)
muestra el paso 2 del apartado "Connect to a remote host" de esas instrucciones mientras que
[esta otra](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/master/img/VSC-password.png)
muestra la ventana de autentificación de VSC para darle acceso a la máquina virtual.  
[Este vídeo](https://youtu.be/pAUfwae-eWg) ilustra cómo configurar la edición remota de ficheros alojados en máquinas IaaS-ULL usando VSC.

15. Utilice el VSC para escribir el código fuente del programa 
[hello_world.cc](https://github.com/fsande/IB-class-code-examples/blob/master/IntroductionToC%2B%2B/hello_world.cc).
Grabe ese fichero en un directorio ~/practicas/ que cree en su máquina virtual.
Acceda a la máquina virtual usando ssh, compile y ejecute ese programa.
Para compilar el programa escriba el siguiente comando 

`$ g++ -std=c++14 -g -Wall -o hello_world hello_world.cc`

Y para ejecutarlo escriba:

`$ ./hello_world`

#### Simplificar la conexión a la VM
16. Siga [estas instrucciones](http://www.linuxproblem.org/art_9.html) 
para establecer la configuración de la máquina de modo que se pueda conectar a ella sin necesidad de escribir el password en cada conexión. 
Para poder conectarse por ssh con las máquinas virtuales de IaaS ull ha de autentificarse en la página [acceso.ull.es](acceso.ull.es).  
Recuerde que en caso de acceder desde fuera de del campus ULL ha de hacerlo mediante una conexión VPN. 
Consulte [esta referencia](https://www.ull.es/servicios/stic/2016/05/10/servicio-de-vpn-de-la-ull/) 
(en el Centro de Cálculo, por ahora no lo necesita) para conectarse a través de vpn.

17. También resulta conveniente utilizar alguno de los métodos (ssh config o alias) que se presentan en 
[estas instrucciones](https://scotch.io/tutorials/how-to-create-an-ssh-shortcut) 
de modo que se simplifique la conexión con la máquina remota pudiendo escribir algo como:
```
$ ssh mi_maquina_ibasica
```
para conectarse a la máquina virtual.
