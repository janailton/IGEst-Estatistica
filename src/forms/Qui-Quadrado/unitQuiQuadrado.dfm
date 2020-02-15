object FormQuiQuadrado: TFormQuiQuadrado
  Left = 293
  Top = 114
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Distribui'#231#227'o Qui-Quadrado'
  ClientHeight = 286
  ClientWidth = 336
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object TabbedNotebook1: TTabbedNotebook
    Left = 7
    Top = 8
    Width = 321
    Height = 273
    TabFont.Charset = DEFAULT_CHARSET
    TabFont.Color = clBtnText
    TabFont.Height = -11
    TabFont.Name = 'Tahoma'
    TabFont.Style = []
    TabOrder = 0
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Qui-Quadrado Inverso'
      object GroupBox1: TGroupBox
        Left = 14
        Top = 8
        Width = 283
        Height = 113
        Caption = 'Dados'
        TabOrder = 0
        object Label1: TLabel
          Left = 16
          Top = 42
          Width = 125
          Height = 13
          Caption = 'Graus de liberdade        =  '
        end
        object Label2: TLabel
          Left = 16
          Top = 74
          Width = 126
          Height = 13
          Caption = 'Probabilidade (%)           =  '
        end
        object EditGLInv: TEdit
          Left = 167
          Top = 39
          Width = 97
          Height = 21
          TabOrder = 0
          Text = '0'
        end
        object EditP: TEdit
          Left = 167
          Top = 66
          Width = 97
          Height = 21
          TabOrder = 1
          Text = '0'
        end
      end
      object GroupBox3: TGroupBox
        Left = 14
        Top = 127
        Width = 283
        Height = 106
        Caption = 'Sa'#237'da'
        TabOrder = 1
        object Label3: TLabel
          Left = 16
          Top = 34
          Width = 127
          Height = 13
          Caption = 'Valor cr'#237'tico X'#178'               =  '
        end
        object BtnCalculaInv: TButton
          Left = 167
          Top = 64
          Width = 97
          Height = 25
          Caption = 'Calcular'
          TabOrder = 0
          OnClick = BtnCalculaInvClick
        end
        object EditResultadoInv: TEdit
          Left = 167
          Top = 28
          Width = 97
          Height = 21
          ReadOnly = True
          TabOrder = 1
        end
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Qui-Quadrado'
      object GroupBox4: TGroupBox
        Left = 14
        Top = 8
        Width = 283
        Height = 113
        Caption = 'Dados'
        TabOrder = 0
        object Label4: TLabel
          Left = 16
          Top = 42
          Width = 125
          Height = 13
          Caption = 'Graus de liberdade        =  '
        end
        object Label5: TLabel
          Left = 16
          Top = 74
          Width = 124
          Height = 13
          Caption = 'X                                   =  '
        end
        object EditGL: TEdit
          Left = 167
          Top = 39
          Width = 97
          Height = 21
          TabOrder = 0
          Text = '0'
        end
        object EditX: TEdit
          Left = 167
          Top = 66
          Width = 97
          Height = 21
          TabOrder = 1
          Text = '0'
        end
      end
      object GroupBox6: TGroupBox
        Left = 14
        Top = 127
        Width = 283
        Height = 105
        Caption = 'Sa'#237'da'
        TabOrder = 1
        object Label6: TLabel
          Left = 16
          Top = 34
          Width = 122
          Height = 13
          Caption = 'Probabilidade X'#178'           =  '
        end
        object btnCalcula: TButton
          Left = 167
          Top = 64
          Width = 97
          Height = 25
          Caption = 'Calcular'
          TabOrder = 0
          OnClick = btnCalculaClick
        end
        object EditResultado: TEdit
          Left = 167
          Top = 28
          Width = 97
          Height = 21
          ReadOnly = True
          TabOrder = 1
        end
      end
    end
  end
end
