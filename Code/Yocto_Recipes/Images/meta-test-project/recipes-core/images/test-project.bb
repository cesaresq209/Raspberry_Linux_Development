#Based on rpi-test-image from raspberry pi layer
require recipes-core/images/rpi-test-image.bb

#Install helloworld gpio application
IMAGE_INSTALL += " \
	gpio \
	"
