make -C driver clean
CONFIGS="-DDNUM_BANKS=1" ./ci/blackbox.sh --driver=rtlsim --cores=1 --app=io_addr --debug

mkdir ~/vagrant-shared/block_name

grep -E "block_name" run.log

grep -f "module instance_name block_name parameters" run.log 

grep -E "module instance_name block_name inputs" run.log | sed 's/.* first_input_name/first_input_name/' > ~/vagrant-shared/block_name/inputs.log

grep -E "module instance_name block_name outputs" run.log | sed 's/.* first_output_name/first_output_name/' > ~/vagrant-shared/block_name/outputs.log
