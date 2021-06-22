#Based on rpi-basic-image from raspberry pi layer
require recipes-core/images/rpi-basic-image.bb

#Install helloworld gpio application
#IMAGE_INSTALL += "gpio "

IMAGE_INSTALL += " \
	gpio \
	"
