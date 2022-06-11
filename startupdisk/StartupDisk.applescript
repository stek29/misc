do shell script "diskutil mount disk0s3"

tell application "System Events"
	tell application "System Preferences"
		set current pane to pane id "com.apple.preference.startupdisk"
		activate
	end tell
	
	tell application process "System Preferences"
		delay 0.3
		
		tell window "Startup Disk"
			set lockFound to false
			repeat with x from 1 to number of buttons
				if lockFound is false then
					if title of button x is "Click the lock to make changes." then
						click button x
						set lockFound to true
						repeat while title of button x is "Authenticating..."
							delay 1
						end repeat
					else if title of button x is "Click the lock to prevent further changes." then
						set lockFound to true
					end if
				else
					exit repeat
				end if
			end repeat
			
			set targetPrefix to "Windows"
			set targetIndex to 0
			set options to group of UI element 1 of scroll area 1
			
			repeat with i from 1 to number of options
				set x to item i of options
				if name of UI element 3 of x starts with targetPrefix then
					set targetIndex to i
					exit repeat
				end if
			end repeat
			
			if targetIndex is 0 then
				error "cant find " & targetPrefix & " in list of options"
			end if
			
			key code 48
			delay 0.1
			
			repeat with i from 1 to number of options
				key code 123
				delay 0.1
			end repeat
			
			repeat with i from 2 to targetIndex
				key code 124
				delay 0.1
			end repeat
			
			click button "RestartÉ"
			delay 0.3
			click button "Restart" of sheet 1
			return true
		end tell
	end tell
end tell
