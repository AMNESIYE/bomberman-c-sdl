# Groupe de vignan_q

## Test Serveur
**Terminal 1 :** *./bomberman -S 1234*

**Terminal 2 :** *netcat 127.0.0.1 1234*

## Test Client
**Terminal 1 :** *./bomberman -C 127.0.0.1 1234*

**Terminal 2 :** *netcat -l -p 1234*
