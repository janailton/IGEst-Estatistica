object FormHipergeometrica: TFormHipergeometrica
  Left = 325
  Top = 99
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Distribui'#231#227'o Hipergeometrica'
  ClientHeight = 273
  ClientWidth = 449
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
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 216
    Height = 145
    Caption = 'Dados:'
    TabOrder = 0
    object Label1: TLabel
      Left = 18
      Top = 32
      Width = 49
      Height = 13
      Caption = 'X            ='
    end
    object Label2: TLabel
      Left = 17
      Top = 59
      Width = 50
      Height = 13
      Caption = 'N            ='
    end
    object Label3: TLabel
      Left = 18
      Top = 86
      Width = 48
      Height = 13
      Caption = 'n            ='
    end
    object Label5: TLabel
      Left = 17
      Top = 113
      Width = 48
      Height = 13
      Caption = 'k            ='
    end
    object EditX: TEdit
      Left = 103
      Top = 29
      Width = 83
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object EditN: TEdit
      Left = 103
      Top = 56
      Width = 83
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object EditNm: TEdit
      Left = 103
      Top = 83
      Width = 83
      Height = 21
      TabOrder = 2
      Text = '0'
    end
    object EditK: TEdit
      Left = 103
      Top = 110
      Width = 83
      Height = 21
      TabOrder = 3
      Text = '0'
    end
  end
  object GroupBox2: TGroupBox
    Left = 232
    Top = 8
    Width = 209
    Height = 145
    Caption = 'M'#233'todo de c'#225'lculo'
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 24
      Top = 47
      Width = 113
      Height = 17
      Caption = 'P ( X = x )'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 112
      Top = 47
      Width = 113
      Height = 17
      Caption = 'P ( X > x )'
      TabOrder = 1
    end
    object RadioButton3: TRadioButton
      Left = 24
      Top = 70
      Width = 113
      Height = 17
      Caption = 'P ( X < x )'
      TabOrder = 2
    end
    object RadioButton4: TRadioButton
      Left = 112
      Top = 70
      Width = 113
      Height = 17
      Caption = 'P ( X >= x )'
      TabOrder = 3
    end
    object RadioButton5: TRadioButton
      Left = 24
      Top = 93
      Width = 113
      Height = 17
      Caption = 'P ( X <= x )'
      TabOrder = 4
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 159
    Width = 433
    Height = 106
    Caption = 'Sa'#237'da'
    TabOrder = 2
    object Label4: TLabel
      Left = 18
      Top = 40
      Width = 66
      Height = 13
      Caption = 'Resultado    ='
    end
    object Button1: TButton
      Left = 256
      Top = 28
      Width = 145
      Height = 25
      Caption = '&Calcular'
      TabOrder = 0
      OnClick = Button1Click
    end
    object EditResultado: TEdit
      Left = 103
      Top = 32
      Width = 113
      Height = 21
      ReadOnly = True
      TabOrder = 2
    end
    object btnAjuda: TButton
      Left = 256
      Top = 59
      Width = 145
      Height = 25
      Caption = '&Ajuda'
      TabOrder = 1
      OnClick = btnAjudaClick
    end
  end
end
