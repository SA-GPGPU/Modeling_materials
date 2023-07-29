mkdir ~/vagrant-shared/block_name

grep -E "block_name" run.log

grep -E "module instance_name block_name parameters" run.log 

grep -E "module instance_name block_name inputs" run.log | sed 's/.* first_input_name/first_input_name/' > ~/vagrant-shared/block_name/inputs.log

grep -E "module instance_name block_name outputs" run.log | sed 's/.* first_output_name/first_output_name/' > ~/vagrant-shared/block_name/outputs.log
