def convert(html_file):
    body = ""
    body += "temp.printf(\""
    f = open(html_file, "r")
    for x in f:
        if(x == "\n"):
            body += "\\n\\\n"
        else:
            body += "\t"+x[:-1].replace("\"", "\\\"") + " \\n\\\n"
    body +=  "\", hr, min % 60, sec % 60, rp2040.getFreeHeap\(), ++cnt);"
    print(body)