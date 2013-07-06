<?xml version="1.0"?>
<anjuta>
    <plugin name="Tools" mandatory="no">
        <require group="Anjuta Plugin"
                 attribute="Location"
                 value="anjuta-tools:ATPPlugin"/>
    </plugin>
    <plugin name="Terminal" mandatory="no">
        <require group="Anjuta Plugin"
                 attribute="Location"
                 value="anjuta-terminal:TerminalPlugin"/>
    </plugin>
    <plugin name="Git" mandatory="no">
        <require group="Anjuta Plugin"
                 attribute="Location"
                 value="anjuta-git:Git"/>
    </plugin>
    <plugin name="GNU Debugger" mandatory="no">
        <require group="Anjuta Plugin"
                 attribute="Location"
                 value="anjuta-gdb:GdbPlugin"/>
    </plugin>
    <plugin name="API Help" mandatory="no">
        <require group="Anjuta Plugin"
                 attribute="Location"
                 value="anjuta-devhelp:AnjutaDevhelp"/>
    </plugin>
</anjuta>
