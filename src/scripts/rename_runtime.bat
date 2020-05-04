@powershell -Command "dir -Path %1 -Recurse -Filter *.vcxproj | ForEach-Object { (Get-Content -Path $_.FullName) -replace 'MultiThreaded', 'MultiThreadedDLL' | Set-Content $_.FullName }"
