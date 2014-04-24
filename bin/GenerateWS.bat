wsdl2h.exe -s -o wpsoap.h http://127.0.0.1:8080/services/printerService?wsdl
soapcpp2.exe -C -L -j -i -w -x wpsoap.h
