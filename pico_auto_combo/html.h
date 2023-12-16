void handle_html(String condition, String loaded_script, String file_name){

  
  static String html = "";

  html.reserve(12000);
  condition.reserve(20);
  loaded_script.reserve(20);
  file_name.reserve(12);


  html = "   <!DOCTYPE html> \n\
                        <html> \n\
                            <head> \n\
                                <title>FightScript Configurator</title> \n\
                                <link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css?family=Sofia\"> \n\
                                <meta http-equiv=\"Cache-control\" content=\"no-cache, no-store, must-revalidate\"> \n\
                                 <meta http-equiv=\"Content-Security-Policy\" content=\"default-src *; style-src 'self' 'unsafe-inline'; script-src 'self' 'unsafe-inline' 'unsafe-eval'\"> \n\
                    <meta http-equiv=\"Pragma\" content=\"no-cache\"> \n\
                                <style> \n\
                                html, body { \n\
                                    height: 100%; \n\
                                    margin: 0; \n\
                                } \n\
                                    #head-bar{ \n\
                                        position: fixed; \n\
                                        display: flex; \n\
                                        flex-direction: row; \n\
                                        align-items: center; \n\
                                        top: 0; \n\
                                        left: 0; \n\
                                        width: 100%; \n\
                                        height: 100px; \n\
                                        background-color: rgb(12, 104, 98); \n\
                                    } \n\
                                    #title-box{ \n\
                                        margin-left: 70px; \n\
                                        font-size: 30px; \n\
                                        font-family: Google Sans,-apple-system,BlinkMacSystemFont,sans-serif; \n\
                                        color: white; \n\
                                    } \n\
                                    #loaded-script{ \n\
                                        margin-left: 70px; \n\
                                        font-size: 20px; \n\
                                        font-family: Google Sans,-apple-system,BlinkMacSystemFont,sans-serif; \n\
                                        color: white; \n\
                                    } \n\
                                    #main-body{ \n\
                                        background-color: #a1a1a1; \n\
                                        height: 100%; \n\
                                        width: 100%; \n\
                                        max-height: 100%; \n\
                                        max-width: 100%; \n\
\n\
                                        display: flex; \n\
                                        flex-direction: column; \n\
\n\
                                    } \n\
                                    #area-wrap{ \n\
                                        margin: 0; \n\
                                        position: absolute; \n\
                                        top: 50%; \n\
                                        left: 25%; \n\
                                        -ms-transform: translate(-25%, -50%); \n\
                                        transform: translate(-25%, -50%); \n\
\n\
                                    } \n\
                                    #row-a, #row-b{ \n\
                                        display: flex; \n\
                                        flex-direction: row; \n\
                                        align-items: center; \n\
                                    } \n\
                                    textarea{ \n\
                                        margin: 20px; \n\
                                        padding: 10px \n\
                                    } \n\
                                    #file-name{ \n\
                                        height: 20px \n\
                                    } \n\
\n\
\n\
\n\
\n\
                                </style> \n\
                            </head> \n\
                            <body> \n\
                                <header id=\"head-bar\"> \n\
                                    <div id=\"title-box\">FightScript Configurator</div> \n\
                                </header> \n\
                                <div id=\"main-body\"> \n\
                                    <div id = \"area-wrap\"> \n\
                                        <input type=\"text\" id =\"file-name\" name=\"file-name\" placeholder=\"name of script\"> \n\
                                        <button type=\"button\" id=\"save-butt\">Save</button> \n\
                                        <button type=\"button\" id=\"load-butt\">Load</button> \n\
                                        <input id='fileid' type='file' accept='.fscript' hidden/> \n\
                                        <a id=\"shits\" hidden></a> \n\
                                        <button type=\"button\" id=\"clear-butt\">Clear Textfields</button> \n\
\n\
                                 \n\
\n\
                                    <form id=\"script-boxes\" method=\"POST\" action=\"/send\"> \n\
                                        <div id=\"row-a\"> \n\
                                            <textarea id=\"script-a\"  rows=\"10\" cols=\"20\"></textarea> \n\
                                            <textarea id=\"script-b\"  rows=\"10\" cols=\"20\"></textarea> \n\
                                            <textarea id=\"script-c\"  rows=\"10\" cols=\"20\"></textarea> \n\
                                            <textarea id=\"script-d\"  rows=\"10\" cols=\"20\"></textarea> \n\
\n\
                                        </div> \n\
                                        <div id=\"row-b\"> \n\
                                            <textarea id=\"script-e\"  rows=\"10\" cols=\"20\"></textarea> \n\
                                            <textarea id=\"script-f\"  rows=\"10\" cols=\"20\"></textarea> \n\
                                            <textarea id=\"script-g\"  rows=\"10\" cols=\"20\"></textarea> \n\
                                            <textarea id=\"script-h\"  rows=\"10\" cols=\"20\"></textarea> \n\
                                            <div id=\"row-b-button-subrows\"> \n\
                                                <button type=\"button\" id=\"upload-button\">Upload</button> \n\
                                            </div> \n\
                                        </div> \n\
                                        <input type=\"hidden\" id=\"compiled\" name=\"compiled\" value=\"\"> \n\
                                    </form> \n\
                                    </div> \n\
                                </div> \n\
                            </body> \n\
                            <script> \n\
\n\
                            const decoder_obj = { \n\
                         \n\
                            'A': \"UHold\", \n\
                            'B': \"URel\", \n\
                            'C': \"UPress\", \n\
                            'D': \"DHold\", \n\
                            'E': \"DRel\", \n\
                            'F': \"DPress\", \n\
                            'G': \"LHold\", \n\
                            'H': \"LRel\", \n\
                            'I': \"LPress\", \n\
                            'J': \"RHold\", \n\
                            'K': \"RRel\", \n\
                            'L': \"RPress\", \n\
                            'M': \"AHold\", \n\
                            'N': \"ARel\", \n\
                            'O': \"APress\", \n\
                            'P': \"BHold\", \n\
                            'Q': \"BRel\", \n\
                            'R': \"BPress\", \n\
                            'S': \"XHold\", \n\
                            'T': \"XRel\", \n\
                            'U': \"XPress\", \n\
                            'V': \"YHold\", \n\
                            'W': \"YRel\", \n\
                            'X': \"YPress\", \n\
                            'Y': \"RBHold\", \n\
                            'Z': \"RBRel\", \n\
                            'a': \"RBPress\", \n\
                            'b': \"RTHold\", \n\
                            'c': \"RTRel\", \n\
                            'd': \"RTPress\", \n\
                            'e': \"LBHold\", \n\
                            'f': \"LBRel\", \n\
                            'g': \"LBPress\", \n\
                            'h': \"LTHold\", \n\
                            'i': \"LTRel\", \n\
                            'j': \"LTPress\", \n\
                            'k': \"QCF\", \n\
                            'l': \"QCB\", \n\
                            'm': \"RQCF\", \n\
                            'n': \"RQCB\", \n\
                            'o': \"HCF\", \n\
                            'p': \"HCB\", \n\
                            'q': \"HCFB\", \n\
                            'r': \"HCBF\", \n\
                            's': \"DP\", \n\
                            't': \"RDP\", \n\
                            'u': \"SPD\", \n\
                            'v': \"delay_frames\", \n\
                            } \n\
                                 \n\
                            const select = \""+condition+"\"; \n\
                            const loaded_script = \""+loaded_script+"\"; \n\
             \n\
                            document.addEventListener(\"DOMContentLoaded\", (event) => { \n\
\n\
\n\
\n\
                                    if(select == \"sent\"){ \n\
                                            loadScript(loaded_script); \n\
                                            setTimeout(function(){ \n\
                                              alert(\"Script Sent!\"); \n\
                                              }, 0); \n\
                                    } \n\
\n\
                                }); \n\
\n\
                                function loadScript(script){ \n\
\n\
                                  const scripts = getScripts(script) \n\
\n\
\n\
                                  document.getElementById(\"script-a\").value = scripts[0]; \n\
                                  document.getElementById(\"script-b\").value = scripts[1]; \n\
                                  document.getElementById(\"script-c\").value = scripts[2]; \n\
                                  document.getElementById(\"script-d\").value = scripts[3]; \n\
                                  document.getElementById(\"script-e\").value = scripts[4]; \n\
                                  document.getElementById(\"script-f\").value = scripts[5]; \n\
                                  document.getElementById(\"script-g\").value = scripts[6]; \n\
                                  document.getElementById(\"script-h\").value = scripts[7].slice(0, -1); \n\
                                } \n\
                          function getScripts(name){ \n\
\n\
                            let temp_num = \"\"; \n\
                            let temp = \"\"; \n\
                            let store_scripts = []; \n\
\n\
                            for(var i = 0; i < name.length; i++){ \n\
                                while(name.charAt(i) != \":\" && i < name.length){ \n\
                                    if(isNum(name.charAt(i))){ \n\
                                        while(isNum(name.charAt(i)) &&  i < name.length){ \n\
                                            temp_num += name.charAt(i); \n\
                                            i++; \n\
                                        } \n\
                                        temp_num += \"\\n\"; \n\
                                        temp += temp_num; \n\
                                        temp_num = \"\"; \n\
                                    } \n\
                                    else{ \n\
                                        temp += decoder_obj[name.charAt(i)]+\"\\n\"; \n\
                                        i++; \n\
                                    } \n\
                                } \n\
                                    temp = temp.replaceAll(\"undefined\", \"\"); \n\
                                    store_scripts.push(temp); \n\
                                    temp = \"\"; \n\
                                    temp_num =\"\"; \n\
                            } \n\
\n\
                            return store_scripts; \n\
                      } \n\
\n\
                                String.prototype.replaceAt = function(index, replacement) { \n\
                                    return this.substring(0, index) +replacement+ this.substring(index + replacement.length); \n\
                                }; \n\
\n\
                                const encoder_obj = { \n\
                                        \"UHold\": 'A', \n\
                                        \"URel\": 'B', \n\
                                        \"UPress\": 'C', \n\
                                        \"DHold\": 'D', \n\
                                        \"DRel\": 'E', \n\
                                        \"DPress\": 'F', \n\
                                        \"LHold\": 'G', \n\
                                        \"LRel\": 'H', \n\
                                        \"LPress\": 'I', \n\
                                        \"RHold\": 'J', \n\
                                        \"RRel\": 'K', \n\
                                        \"RPress\": 'L', \n\
                                        \"AHold\": 'M', \n\
                                        \"ARel\": 'N', \n\
                                        \"APress\": 'O', \n\
                                        \"BHold\": 'P', \n\
                                        \"BRel\": 'Q', \n\
                                        \"BPress\": 'R', \n\
                                        \"XHold\": 'S', \n\
                                        \"XRel\": 'T', \n\
                                        \"XPress\": 'U', \n\
                                        \"YHold\": 'V', \n\
                                        \"YRel\": 'W', \n\
                                        \"YPress\": 'X', \n\
                                        \"RBHold\": 'Y', \n\
                                        \"RBRel\": 'Z', \n\
                                        \"RBPress\": 'a', \n\
                                        \"RTHold\": 'b', \n\
                                        \"RTRel\": 'c', \n\
                                        \"RTPress\": 'd', \n\
                                        \"LBHold\": 'e', \n\
                                        \"LBRel\": 'f', \n\
                                        \"LBPress\": 'g', \n\
                                        \"LTHold\": 'h', \n\
                                        \"LTRel\": 'i', \n\
                                        \"LTPress\": 'j', \n\
                                        \"QCF\": 'k', \n\
                                        \"QCB\": 'l', \n\
                                        \"RQCF\": 'm', \n\
                                        \"RQCB\": 'n', \n\
                                        \"HCF\": 'o', \n\
                                        \"HCB\": 'p', \n\
                                        \"HCFB\": 'q', \n\
                                        \"HCBF\": 'r', \n\
                                        \"DP\": 's', \n\
                                        \"RDP\": 't', \n\
                                        \"SPD\": 'u', \n\
                                        \"delay_frames\": 'v', \n\
\n\
\n\
\n\
                                }; \n\
\n\
                                document.getElementById(\"load-butt\").addEventListener(\"click\", load_script); \n\
                                document.getElementById(\"save-butt\").addEventListener(\"click\", save_script); \n\
                                document.getElementById(\"upload-button\").addEventListener(\"click\", submit); \n\
                                document.getElementById(\"clear-butt\").addEventListener(\"click\", clear_fields); \n\
                                document.getElementById('fileid').addEventListener(\"change\", read_script); \n\
\n\
                                function clear_fields(){ \n\
                                  document.getElementById(\"script-a\").value = \"\"; \n\
                                  document.getElementById(\"script-b\").value = \"\"; \n\
                                  document.getElementById(\"script-c\").value = \"\"; \n\
                                  document.getElementById(\"script-d\").value = \"\"; \n\
                                  document.getElementById(\"script-e\").value = \"\"; \n\
                                  document.getElementById(\"script-f\").value = \"\"; \n\
                                  document.getElementById(\"script-g\").value = \"\"; \n\
                                  document.getElementById(\"script-h\").value = \"\"; \n\
                                } \n\
\n\
                                function load_script(){ \n\
           \n\
                                     \n\
                                        document.getElementById('fileid').click(); \n\
                     \n\
\n\
                                } \n\
                                function read_script(){ \n\
                                         \n\
                                        let fr = new FileReader(); \n\
                                                fr.onload = function () { \n\
                                                    loadScript(fr.result); \n\
                                                } \n\
                                 \n\
                                        fr.readAsText(this.files[0]); \n\
                                } \n\
\n\
                                function save_script(){ \n\
                                    let file_name = document.getElementById(\"file-name\").value; \n\
\n\
                                    if(file_name != \"\" && compile() != \"nope\"){ \n\
                                        let penis = document.getElementById(\"shits\"); \n\
                                        shits.href = \"data:application/xml;charset=utf-8,\"+compile(); \n\
                                        shits.download = file_name+\".fscript\"; \n\
                                        shits.click() \n\
                                    } \n\
                                    else{ \n\
                                        alert(\"No name specified for file.\"); \n\
                                    } \n\
                                } \n\
\n\
                                function compile(){ \n\
                                     \n\
             \n\
                                    let script = \"script-a\"; \n\
                                    let compiled = \"\"; \n\
\n\
\n\
\n\
                                    for(var i = 0; i < 8; i++){ \n\
\n\
                                        let fightscript_args = document.getElementById(script).value.split(\"\\n\"); \n\
                                        if(fightscript_args.length > 512){ \n\
                                            alert(script + \" has too many arguments/lines (max: 512)\"); \n\
                                            return \"nope\"; \n\
                                        } \n\
\n\
\n\                                     
                                        for(var j = 0; j < fightscript_args.length; j++){ \n\
                                            if(!(fightscript_args.length == 1  && fightscript_args[0] == \"\")){ \n\
                                                if(encoder_obj[fightscript_args[j]]){ \n\
                                                    compiled += encoder_obj[fightscript_args[j]]; \n\
                                                } \n\
                                                else if(isNum(fightscript_args[j]) && fightscript_args[j] != \"\" && fightscript_args[j].length < 5){ \n\
                                                    compiled += fightscript_args[j]; \n\
                                                } \n\
                                                else if(fightscript_args[j] == \"\"){ \n\
                                                    //do nothing if box is empty or line is empty \n\
                                                } \n\
                                                else{ \n\
                                                    if(isNum(fightscript_args[j])){ \n\
                                                        alert( script + \" has invalid command \" + fightscript_args[j] +\"(delay must not exceed 9999)\"); \n\
                                                        return \"nope\"; \n\
                                                    } \n\
                                                    else{ \n\
                                                        alert( script + \" has invalid command \" + fightscript_args[j]); \n\
                                                        return \"nope\"; \n\
                                                    } \n\
                                                } \n\
                                            } \n\
                                            else{\n\
                                              compiled += \"1\";\n\
                                            } \n\
                                          } \n\
                                        compiled += \":\"; \n\
                                        script =  script.replaceAt(7, String.fromCharCode(script.charCodeAt(7) + 1)); \n\
                                    } \n\
\n\
\n\
                                    compiled = compiled.slice(0, -1); \n\
                                    return compiled; \n\
                                     \n\
\n\
                                } \n\
\n\
                                function submit(){ \n\
                                    if(confirm(\"This will overwrite any profile of the same name, are you sure?\") && compile() != \"nope\"){ \n\
                                        document.getElementById(\"compiled\").value = compile(); \n\
                                        document.getElementById(\"script-boxes\").submit(); \n\
                                    } \n\
                                } \n\
\n\
                                function isNum(str){ \n\
\n\
                                    for(var i = 0; i < str.length; i++){ \n\
                                        let x = str.charCodeAt(i); \n\
\n\
                                        if(!(x > 47 && x < 58)){ \n\
                                            return false; \n\
                                        } \n\
                                    } \n\
\n\
                                    return true; \n\
\n\
                                } \n\
\n\
                            </script> \n\
                        </html>";
      server.send(200, "text/html", html);
}