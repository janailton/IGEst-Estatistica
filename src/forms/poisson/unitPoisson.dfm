object FormPoisson: TFormPoisson
  Left = 354
  Top = 121
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Distribui'#231#227'o Poisson'
  ClientHeight = 234
  ClientWidth = 497
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
    Width = 251
    Height = 121
    Caption = 'Dados'
    TabOrder = 0
    object Label1: TLabel
      Left = 35
      Top = 37
      Width = 64
      Height = 13
      Caption = 'X                 ='
    end
    object Label2: TLabel
      Left = 30
      Top = 78
      Width = 65
      Height = 13
      Caption = 'Lambda       ='
    end
    object EditX: TEdit
      Left = 124
      Top = 29
      Width = 107
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object EditLambda: TEdit
      Left = 124
      Top = 69
      Width = 107
      Height = 21
      TabOrder = 1
      Text = '0'
    end
  end
  object GroupBox2: TGroupBox
    Left = 265
    Top = 8
    Width = 224
    Height = 121
    Caption = 'M'#233'todo de c'#225'clulo'
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 30
      Top = 32
      Width = 76
      Height = 17
      Caption = 'P ( X = x )'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 124
      Top = 31
      Width = 77
      Height = 17
      Caption = 'P ( X > x )'
      TabOrder = 1
    end
    object RadioButton3: TRadioButton
      Left = 30
      Top = 54
      Width = 76
      Height = 17
      Caption = 'P ( X < x )'
      TabOrder = 2
    end
    object RadioButton4: TRadioButton
      Left = 124
      Top = 54
      Width = 77
      Height = 17
      Caption = 'P ( X >= x )'
      TabOrder = 3
    end
    object RadioButton5: TRadioButton
      Left = 30
      Top = 77
      Width = 76
      Height = 17
      Caption = 'P ( X <= x )'
      TabOrder = 4
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 135
    Width = 481
    Height = 90
    Caption = 'Sa'#237'da'
    TabOrder = 2
    object Label4: TLabel
      Left = 30
      Top = 49
      Width = 69
      Height = 13
      Caption = 'Resultado     ='
    end
    object Button1: TButton
      Left = 298
      Top = 36
      Width = 144
      Height = 25
      Caption = 'Calcular'
      TabOrder = 0
      OnClick = Button1Click
    end
    object EditResultado: TEdit
      Left = 124
      Top = 41
      Width = 107
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
  end
end
