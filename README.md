touch delta.txt && echo "Linux Port scanner :)" > delta.txt

# $~ help:


cd src

g++ scan.cpp -o scan

g++ scan2.cpp -o scan2

./scan (ip) (port)
  
<b> ex: </b>
  
./scan 0.0.0.0 80

  
./scan2 (ip) (starting port) (ending port)
  
<b> ex: </b>
  
./scan 0.0.0.0 1 1000

  
  
# Not finished yet!
