object FormFDistr: TFormFDistr
  Left = 234
  Top = 131
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Distribui'#231#227'o F (Inversa)'
  ClientHeight = 256
  ClientWidth = 315
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
    Width = 297
    Height = 121
    Caption = 'Dados'
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 32
      Width = 102
      Height = 13
      Caption = 'GL. Numerador        ='
    end
    object Label2: TLabel
      Left = 24
      Top = 59
      Width = 104
      Height = 13
      Caption = 'G.L. Denominador    ='
    end
    object Label3: TLabel
      Left = 24
      Top = 89
      Width = 101
      Height = 13
      Caption = 'Confian'#231'a (%)          ='
    end
    object EditglNumerador: TEdit
      Left = 177
      Top = 29
      Width = 104
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object EditglDenominador: TEdit
      Left = 177
      Top = 56
      Width = 104
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object EditAlpha: TEdit
      Left = 177
      Top = 83
      Width = 104
      Height = 21
      TabOrder = 2
      Text = '0'
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 135
    Width = 297
    Height = 114
    Caption = 'Sa'#237'da'
    TabOrder = 1
    object Label4: TLabel
      Left = 24
      Top = 44
      Width = 87
      Height = 13
      Caption = 'Resultado           ='
    end
    object Button1: TButton
      Left = 173
      Top = 72
      Width = 108
      Height = 25
      Caption = 'Calcular'
      TabOrder = 0
      OnClick = Button1Click
    end
    object EditResultado: TEdit
      Left = 177
      Top = 36
      Width = 104
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
  end
end
