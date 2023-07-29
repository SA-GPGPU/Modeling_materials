`ifdef DBG_TRACE_CORE_ICACHE
always @(posedge clk) begin
        
    dpi_trace ("module %m block_name parameters width= %0d, length= %0d\n", width, length);

    dpi_trace ("module %m block_name inputs reset= %0d, valid= %0d\n", reset, valid);

    dpi_trace ("module %m block_name outputs valid= %0d", valid);
    dpi_trace ("result=");
    for(int i=0;i<ARR_SIZE;i++){
        dpi_trace(" %0d,", result[i]);
    }
    dpi_trace("\n");
end
`endif
