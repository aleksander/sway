#include <string.h>
#include "commands.h"
#include "input.h"

struct cmd_results *input_cmd_natural_scroll(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "natural_scroll", EXPECTED_AT_LEAST, 1))) {
		return error;
	}
	if (!current_input_config) {
		return cmd_results_new(CMD_FAILURE, "natural_scoll", "No input device defined.");
	}
	struct input_config *new_config = new_input_config(current_input_config->identifier);

	if (strcasecmp(argv[0], "enabled") == 0) {
		new_config->natural_scroll = 1;
	} else if (strcasecmp(argv[0], "disabled") == 0) {
		new_config->natural_scroll = 0;
	} else {
		return cmd_results_new(CMD_INVALID, "natural_scroll", "Expected 'natural_scroll <enabled|disabled>'");
	}

	input_cmd_apply(new_config);
	return cmd_results_new(CMD_SUCCESS, NULL, NULL);
}
