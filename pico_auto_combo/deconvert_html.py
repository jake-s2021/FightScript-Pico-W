def convert(html_file):
    body = ""
    f = open(html_file, "r")
    for x in f:
        body += "\t"+x[:-1].replace("\\\"", "\"").replace("\\n\\" ,"\n" )
    print(body)

