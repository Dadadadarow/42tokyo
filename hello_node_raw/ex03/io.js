{
	const fs = require("fs");
	var full = process.argv[2];
	try
	{
		console.log(toString(fs.readFileSync(full)));
	}
	catch
	{
		
	}
}
