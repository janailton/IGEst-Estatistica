; example2.nsi
;
; This script is based on example1.nsi, but it remember the directory, 
; has uninstall support and (optionally) installs start menu shortcuts.
;
; It will install example2.nsi into a directory that the user selects,

;--------------------------------

; The name of the installer
Name "IGEst"

; The file to write
OutFile "IGEst.exe"

; The default installation directory
InstallDir $PROGRAMFILES\IGEst

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\IGEst" "Install_Dir"

; Request application privileges for Windows Vista
RequestExecutionLevel admin

LoadLanguageFile "${NSISDIR}\Contrib\Language files\PortugueseBR.nlf"

;--------------------------------

; Pages

Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; The stuff to install
Section "IGEst (required)"

  SectionIn RO
  
  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Put file there
  File "..\bin\IGEst.exe"
  File "..\bin\eylan-hardware-api.dll"
  File "..\docs\README"
  File "..\docs\COPYING"
   
  WriteUninstaller "$INSTDIR\uninstall.exe"
  ;CreateDirectory "$APPDATA\IGEst"
  
  SetOutPath "$INSTDIR\pdf"
  
  File "..\pdf\Correlacao.pdf"
  File "..\pdf\Distribuicao_binomial.pdf"
  File "..\pdf\Distribuicao_de_Poisson.pdf"
  File "..\pdf\Distribuicao_F_de_Fisher-Snedecor.pdf"
  File "..\pdf\Distribuicao_hipergeometrica.pdf"
  File "..\pdf\Distribuicao_log-normal.pdf"
  File "..\pdf\Distribuicao_normal.pdf"
  File "..\pdf\Distribuicao_t_de_Student.pdf"
  File "..\pdf\Estatistica_descritiva.pdf"
  File "..\pdf\Funcao_distribuicao_acumulada.pdf"
  File "..\pdf\Media_aritmetica_ponderada.pdf"
  File "..\pdf\Mediana.pdf"
  File "..\pdf\Moda.pdf"
  File "..\pdf\Percentil.pdf"
  File "..\pdf\Quantil.pdf"
  File "..\pdf\Qui-quadrado.pdf"
  File "..\pdf\Regressao_linear.pdf"
  File "..\pdf\Teste_de_normalidade.pdf"
  File "..\pdf\Teste_de_Wilcoxon.pdf"
  File "..\pdf\Testes_de_hipoteses.pdf"
  File "..\pdf\Valor-p.pdf"
  
  SetOutPath "$INSTDIR\include"
  File "..\src\PluginManager\Plugin.h"
  
  SetOutPath "$INSTDIR\Plugins"
  File "..\bin\Plugins\coloque os plugins nessa pasta.txt"
  
SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\IGEst"
  CreateDirectory "$SMPROGRAMS\IGEst\pdf"
  CreateDirectory "$SMPROGRAMS\IGEst\Plugins"
  CreateDirectory "$SMPROGRAMS\IGEst\include"
  CreateShortcut "$SMPROGRAMS\IGEst\IGEst.lnk" "$INSTDIR\IGEst.exe" "" "$INSTDIR\IGEst.exe" 0
  CreateShortcut "$DESKTOP\IGEst.lnk" "$INSTDIR\IGEst.exe" "" "$INSTDIR\IGEst.exe" 0
  Exec '"$INSTDIR\IGEst.exe"'
SectionEnd

;--------------------------------

; Uninstaller

Section "Uninstall"
  
  ; Remove files and uninstaller
  Delete $INSTDIR\IGEst.exe
  Delete $INSTDIR\eylan-hardware-api.dll
  Delete $INSTDIR\pdf\*.*
  Delete $INSTDIR\pdf
  Delete $INSTDIR\Plugins\*.*
  Delete $INSTDIR\include\*.*
  Delete $INSTDIR\uninstall.exe
  Delete $INSTDIR\README
  Delete $INSTDIR\COPYING
  Delete $DESKTOP\IGEst.lnk
  Delete $SMPROGRAMS\IGEst\IGEst.lnk

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\IGEst\*.*"

  ; Remove directories used
  RMDir "$SMPROGRAMS\IGEst"
  RMDir "$INSTDIR\pdf"
  RMDir "$INSTDIR\Plugins"
  RMDir "$INSTDIR\include"
  RMDir "$INSTDIR"

SectionEnd
