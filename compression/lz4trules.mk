# Compress binary file
$(BUILD_DIR)/%.szp: $(BUILD_DIR)/%.bin
	$(call print,Compressing:,$<,$@)
	$(V)$(LZ4UPACK) $< $@
	$(V)$(LZ4TPACK) $< $@.lz4t
	$(V)$(LZ4PACK) $< $@.lz4
	$(V)$(YAY0TOOL) $< $@.yay0
	$(V)$(LZ4UPACK) $< $@.lz4u

# convert binary szp to object file
$(BUILD_DIR)/%.szp.o: $(BUILD_DIR)/%.szp
	$(call print,Converting LZ4T to ELF:,$<,$@)
	$(V)$(LD) -r -b binary $< -o $@
