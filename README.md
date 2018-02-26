# ROS ile Robotik Atölyesi

### ROS'un yüklenmesi ve Gazebo Modellerinin indirilmesi

Dilerseniz ROS'un [kendi sitesindeki yükleme talimatları](http://wiki.ros.org/Installation)'na bağlı kalabilirsiniz veya [bu repo](https://github.com/incebellipipo/ros-install-script)daki çok daha basit yükleme adımlarını takip edebilirsiniz.

> wiki.ros.org içerisindeki bilgilerle yükleme yaparken ubuntudan başka bir dağıtım içerisine yükleme yapacaksanız, ROS repolarının sisteminize eklendiği [satır](http://wiki.ros.org/Installation/Ubuntu#Installation.2BAC8-Ubuntu.2BAC8-Sources-3.Setup_your_sources.list)daki `$(lsb_release -sc)` komutu ubuntu kod isimlerinden başka isimler üretecektir, bu durum ise yüklemenin hatalı olmasına sebep olacaktır. Böylesi bir durumun oluşmaması için `$(lsb_release -sc)` yerine `xenial` yazın.

#### Tek satırlık basit yükleme

Bu betikle yükleme yaparken _Full desktop_ ve _Install all qt ros packages_ seçilmelidir

    # ROS
    bash <(curl -fsSL https://git.io/vNgUe) ros_ws kinetic

    # Gazebo modelleri
    bash <(curl -fsSL https://git.io/vArbM)

### Bu reponun klonlanması gereken yer

ROS yüklendikten sonra `~/ros_ws/src` dizine klonlanmalıdır. _Catkin Workspace dizini genellikle `catkin_ws` olarak isimlendirilir, bu isimlendirme şart değildir._

### Gerekli paketlerin kurulası

    rosrun ab18ros install-required-packages.sh
