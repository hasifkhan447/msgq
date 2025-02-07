arch = stm32f3_disco
install_point = ~/zephyrproject/zephyr/

proj_dir = $(shell pwd)

# build:
# 	distrobox-enter --root ubuntu-24-04-root -- bash -c "source ~/zephyrproject/.venv/bin/activate; cd $(install_point); west -v build -b $(arch) $(proj_dir) -d $(proj_dir)/../build;"

# buildp:
# 	distrobox-enter --root ubuntu-24-04-root -- bash -c "source ~/zephyrproject/.venv/bin/activate; cd $(install_point); west build -b $(arch) -p always $(proj_dir) -d $(proj_dir)/../build;"

# run:
# 	distrobox-enter --root ubuntu-24-04-root -- bash -c "source ~/zephyrproject/.venv/bin/activate; cd $(install_point); west build -b $(arch) $(proj_dir) --build-dir $(proj_dir)/../build -t run;"

# flash:
# 	distrobox-enter --root ubuntu-24-04-root -- bash -c "source ~/zephyrproject/.venv/bin/activate; cd $(install_point); west flash --build-dir $(proj_dir)/../build;"




build:
	cd $(install_point); west -v build -b $(arch) $(proj_dir) -d $(proj_dir)/../build;

buildp:
	cd $(install_point); west build -b $(arch) -p always $(proj_dir) -d $(proj_dir)/../build;

run:
	cd $(install_point); west build -b $(arch) $(proj_dir) --build-dir $(proj_dir)/../build -t run;

flash:
	cd $(install_point); west flash --build-dir $(proj_dir)/../build;









