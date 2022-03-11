cmd_/home/pi/Linux_Drivers/Module.symvers := sed 's/ko$$/o/' /home/pi/Linux_Drivers/modules.order | scripts/mod/modpost -m -a   -o /home/pi/Linux_Drivers/Module.symvers -e -i Module.symvers   -T -
