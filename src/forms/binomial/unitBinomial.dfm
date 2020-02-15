object FormBinomial: TFormBinomial
  Left = 293
  Top = 114
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Distribui'#231#227'o Binomial'
  ClientHeight = 266
  ClientWidth = 434
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
    Width = 209
    Height = 129
    Caption = 'Distribui'#231#227'o Binomial'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 42
      Width = 49
      Height = 13
      Caption = 'X          =  '
    end
    object Label2: TLabel
      Left = 15
      Top = 64
      Width = 42
      Height = 13
      Caption = 'n          ='
    end
    object Label3: TLabel
      Left = 15
      Top = 91
      Width = 43
      Height = 13
      Caption = 'P          ='
    end
    object EditX: TEdit
      Left = 96
      Top = 39
      Width = 97
      Height = 21
      TabOrder = 0
    end
    object EditN: TEdit
      Left = 96
      Top = 66
      Width = 97
      Height = 21
      TabOrder = 1
    end
    object EditP: TEdit
      Left = 96
      Top = 93
      Width = 97
      Height = 21
      TabOrder = 2
    end
  end
  object GroupBox2: TGroupBox
    Left = 223
    Top = 8
    Width = 202
    Height = 129
    Caption = 'M'#233'todo de c'#225'lculo'
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 23
      Top = 41
      Width = 74
      Height = 17
      Caption = 'P ( X = x )'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 111
      Top = 41
      Width = 74
      Height = 17
      Caption = 'P ( X > x )'
      TabOrder = 1
    end
    object RadioButton3: TRadioButton
      Left = 22
      Top = 64
      Width = 67
      Height = 17
      Caption = 'P ( X < x )'
      TabOrder = 2
    end
    object RadioButton4: TRadioButton
      Left = 111
      Top = 64
      Width = 74
      Height = 17
      Caption = 'P ( X >= x )'
      TabOrder = 3
    end
    object RadioButton5: TRadioButton
      Left = 22
      Top = 87
      Width = 83
      Height = 17
      Caption = 'P ( X <= x )'
      TabOrder = 4
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 143
    Width = 417
    Height = 114
    Caption = 'Sa'#237'da'
    TabOrder = 2
    object Label4: TLabel
      Left = 15
      Top = 44
      Width = 66
      Height = 13
      Caption = 'Resultado    ='
    end
    object Button1: TButton
      Left = 256
      Top = 32
      Width = 144
      Height = 25
      Caption = '&Calcular'
      TabOrder = 0
      OnClick = Button1Click
    end
    object EditResultado: TEdit
      Left = 112
      Top = 36
      Width = 113
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object btnAjuda: TButton
      Left = 256
      Top = 63
      Width = 144
      Height = 25
      Caption = '&Ajuda'
      TabOrder = 2
      OnClick = btnAjudaClick
    end
  end
end
